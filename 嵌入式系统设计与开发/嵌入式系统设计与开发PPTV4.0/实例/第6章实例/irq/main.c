/********************************************************
*Name: main.c
*Desc: S3C6410裸机中断程序的主程序，该主程序什么也不做
*关闭LED灯后进进入死循环
*Author: yoyoba(stuyou@126.com)
*Date: 2014-6-7
*Modify: 2016-4-8
*********************************************************/

#include "irq.h"

int main()
{
	led_display(LED_ALL_OFF);//关闭所有LED灯后进入死循环	
	while(1);
	return 0;
}
