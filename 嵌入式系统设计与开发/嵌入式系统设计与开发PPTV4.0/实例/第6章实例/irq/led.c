/********************************************************
*Name: led.c
*Desc: S3C6410裸机中断程序的LED相关函数
*Author: yoyoba(stuyou@126.com)
*Date: 2014-6-7
*Modify: 2016-4-8
*********************************************************/

#include "irq.h"

void delay()
{
	volatile int i = 0x500000;
	while (i--);
}


//LED初始化函数，配置GPK4~7为输出功能
void led_init()
{
	GPKCON0=(GPKCON0&~(0xffffU<<16))
			|GPK4_OUT
			|GPK5_OUT
			|GPK6_OUT
			|GPK7_OUT;
}

//LED点亮函数，通过state变量，控制LED点亮或熄灭
void led_display(int state)
{
	GPKDAT=(GPKDAT&~(0xf<<4))|((state&0xf)<<4);
}

