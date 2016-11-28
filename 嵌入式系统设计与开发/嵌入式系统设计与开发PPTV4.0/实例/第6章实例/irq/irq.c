/********************************************************
*Name: irq.c
*Desc: S3C6410裸机中断程序的中断相关函数
*Author: yoyoba(stuyou@126.com)
*Date: 2014-6-7
*Modify: 2016-4-10
*********************************************************/

#include "irq.h"

extern unsigned long do_irq;

//按键处理程序
void key_isr(void)
{
	unsigned long key_press=0;
	key_press=(EINT0PEND & 0xf);//读EINT0PEND[3:0]，判断哪个键按下

	switch(key_press)
	{	//key1按下
		case 1:
		{
			led_display(LED_ALL_OFF);
			led_display(LED1_ON);
			break;
		}
		//key2按下
		case 2:
		{
			led_display(LED_ALL_OFF);
			led_display(LED2_ON);
			break;
		}
		//key3按下
		case 4:
		{
			led_display(LED_ALL_OFF);
			led_display(LED3_ON);
			break;
		}
		//key4按下
		case 8:
		{
			led_display(LED_ALL_OFF);
			led_display(LED4_ON);
			break;
		}

		default:
			break;

	}
	
	//清中断
	EINT0PEND   = 0xf;
	VIC0ADDRESS = 0;
}

//中断初始化函数，包括中断源初始化、中断控制器初始化
void irq_init(void)
{
	//中断源初始化开始
	/* 配置GPN0~3引脚为中断功能 */
	GPNCON &= ~(0xff);
	GPNCON |= 0xaa;

	/* 设置中断触发方式为: 下降沿触发 */
	EINT0CON0 &= ~(0xff);
	EINT0CON0 |= 0x22;

	/* 开启中断 */
	EINT0MASK &= ~(0xf);
	//中断源初始化结束

	//中断控制器初始化开始
	VIC0INTENCLEAR |= (0x1);//中断控制器关闭中断
	VIC0INTSELECT &= (~(0x1));//设定0号中断源的中断类型为IRQ
	VIC0ADDRESS = 0;//清中断
	
	//中断服务函数入口地址赋值给VIC0VECTADDR0
	//中断发生时，CPU会自动到VIC0VECTADDR0读取
	//中断服务程序的入口地址，执行中断服务函数
	//配置VIC_PORT使能模式下，中断发生不会进入
	//异常向量，避免使用sys_bus模式处理中断
	VIC0VECTADDR0 = (unsigned long)&do_irq;
	
	/* 在中断控制器里使能这些中断 */
	VIC0INTENABLE |= (0x1); /* bit0: EINT0~3 */
	//中断控制器初始化结束
}		


/*void do_irq(void)
{
	//此段代码是sys_bus模式下的中断处理方式
	//此种方式在tiny6410下貌似调试不通
	void (*the_isr)(void);

	the_isr = VIC0ADDRESS;

	the_isr();

	EINT0PEND   = 0xf;
	VIC0ADDRESS = 0;
} */


