/********************************************************
*Name: main.c
*Desc: S3C6410裸机程序点亮LED灯，使用C语言主函数，点灯
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2014-5-2
*Modify: 2016-4-11
*********************************************************/
#include "led.h"

int main()
{
	GPKCON0=(GPKCON0&~(0xFFFFU<<16))|GPK4_OUT|GPK5_OUT|GPK6_OUT|GPK7_OUT;
	//配置GPKCON0寄存器，使得GPK4~7为输出端口，同时GPKCON0的其余位保持不变
	// 跑马灯
	while (1)
	{
		led_display(LED_ALL_OFF);
		delay();
		led_display(LED1_ON);
		delay();
		led_display(LED2_ON);
		delay();
		led_display(LED3_ON);
		delay();
		led_display(LED4_ON);
		delay();
		led_display(LED_ALL_ON);
		delay();
	}
	
	return 0;
}

