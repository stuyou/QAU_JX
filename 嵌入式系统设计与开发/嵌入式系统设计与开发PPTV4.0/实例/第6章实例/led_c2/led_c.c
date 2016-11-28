/********************************************************
*Name: main.c
*Desc: S3C6410裸机程序点亮LED灯，使用C语言。LED相关函数
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2014-5-2
*Modify: 2016-4-11
*********************************************************/

#include "led.h"

// 延时函数
void delay()
{
	volatile int i = 0x500000;
	while (i--);
}

//LED点亮函数，通过state变量，控制LED点亮或熄灭
void led_display(int state)
{
	GPKDAT=(GPKDAT&~(0xf<<4))|((state&0xf)<<4);
}

