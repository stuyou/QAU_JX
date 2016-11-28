/********************************************************
*Name:linux_button_led.c
*Desc: 基于LINUX的按键控制LED程序。当按下KEY1~KEY4时
*分别点亮LED1~LED4，间隔一会后熄灭
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2012-2-4
*Modify: 2016-4-11
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>

//延时函数
void delay()
{
	int i;	
	for(i=0;i<70000000;i++);
}

int main(void)
{
	int fd_led,fd_button;
	char down='1';
	
	//打开LED设备
	fd_led = open("/dev/leds", 0);//打开LED
	if (fd_led ==-1) 
	{
		perror("open device leds");
		exit(1);
	}
	
	//打开key设备
	fd_button = open("/dev/buttons", 0);//打开key
	if (fd_button < 0) 
	{
		perror("open device buttons");
		exit(1);
	}
	
	while(1)
	{
		char current_buttons[8];
		
		if (read(fd_button, current_buttons, sizeof current_buttons) != sizeof current_buttons) 
		{
			perror("read buttons:");
			exit(1);
		}
		
		if(current_buttons[0]==down)//key1按下
		{	
			ioctl(fd_led,1,0);//LED1点亮；
			delay();
			ioctl(fd_led,0,0);//LED1熄灭；
		}
		
		if(current_buttons[1]==down)//key2按下
		{		
			ioctl(fd_led,1,1);//LED2点亮；
			delay();
			ioctl(fd_led,0,1);//LED2熄灭；
		}
			
		if(current_buttons[2]==down)//key3按下
		{
			ioctl(fd_led,1,2);//LED3点亮；
			delay();
			ioctl(fd_led,0,2);//LED3熄灭；
		}
			
		if(current_buttons[3]==down)//key4按下
		{
			ioctl(fd_led,1,3);//LED4点亮；
			delay();
			ioctl(fd_led,0,3);//LED4熄灭；
		}
	}

	close(fd_led);
	close(fd_button);

	return 0;
}
