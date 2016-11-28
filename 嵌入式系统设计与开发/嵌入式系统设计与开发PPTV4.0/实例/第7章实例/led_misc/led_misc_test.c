/********************************************************
*Name:led_misc_test.c
*Desc: LED杂项设备驱动程序的测试程序
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2016-2-4
*Modify: 2016-4-11
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//延时函数
void delay()
{
	int i;	
	for(i=0;i<70000000;i++);
}

int main()
{
	int fd;

	fd = open("/dev/myled_misc", 0);//打开LED设备，返回文件描述符
	if (fd ==-1) 
	{
		perror("open device leds");
		exit(1);
	}
	
	fprintf(stdout,"fd=%d\n",fd);	//输出LED文件描述符
	
	while(1)
	{
		/*ioctl(fd, on, led_no)函数，用来控制LED灯。
		on=1，点亮LED，on=0，熄灭LED；
		led_no取值为0、1、2、3，
		分别代表LED1、LED2、LED3、LED4*/
		ioctl(fd,1,0);//LED1点亮
		fprintf(stdout,"LED 1 ON\n"); 
		delay();
		ioctl(fd,0,0);//LED1熄灭
		fprintf(stdout,"LED 1 OFF\n");
		delay();

		ioctl(fd,1,1); //LED2点亮
		fprintf(stdout,"LED 2 ON\n");
		delay();
		ioctl(fd,0,1); //LED2熄灭
		fprintf(stdout,"LED 2 OFF\n");
		delay();

		ioctl(fd,1,2); //LED3点亮
		fprintf(stdout,"LED 3 ON\n");
		delay();
		ioctl(fd,0,2); //LED1熄灭
		fprintf(stdout,"LED 3 OFF\n");
		delay();

		ioctl(fd,1,3); //LED4点亮
		fprintf(stdout,"LED 4 ON\n");
		delay();
		ioctl(fd,0,3); //LED1熄灭
		fprintf(stdout,"LED 4 OFF\n");
		delay();
	}
	close(fd);
	return 0;
}
