/********************************************************
*Name:led_drv_test.c
*Desc: LED驱动程序的测试程序
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2016-2-4
*Modify: 2016-4-11
*********************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/*
leddrvtest on:打开LED1~LED4
leddrvtest off:熄灭LED1~LED4
*/
int main(int argc, char **argv)
{
	int fd;
	int val = 1;
	
	fd = open("/dev/myled_drv", O_RDWR);
	
	if (fd < 0)
	{
		printf("can't open!\n");
	}

	if (argc != 2)
		{
			printf("Usage:\n");
			printf("%s <on|off>\n",argv[0]);
			return 0;
		}

	if (strcmp(argv[1], "on") == 0)
		{
			val = 1;
		}
	else
		{
			val = 0;
		}
	
	write(fd, &val, 4);
	
	return 0;
}

