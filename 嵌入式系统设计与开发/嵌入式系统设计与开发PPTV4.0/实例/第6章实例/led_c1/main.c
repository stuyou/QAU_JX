/********************************************************
*Name: start.S
*Desc: S3C6410裸机程序点亮LED灯，使用C语言点灯
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2014-6-4
*Modify: 2016-4-11
*********************************************************/

// 延时
void delay()
{
	volatile int i = 0x500000;
	while (i--);
}

int main()
{
	// 配置引脚
	volatile unsigned long *gpkcon0 = (volatile unsigned long *)0x7F008800;
	volatile unsigned long *gpkdat = (volatile unsigned long *)0x7F008808;
	
	*gpkcon0 = 0x11110000;	//配置GPK4/5/6/7为输出功能

	// 跑马灯
	while (1)
	{
        *gpkdat=0x000000f0;    //GPKDAT=0x000000f0,GPKDAT[7:4]=1111,4个LED全灭
        delay();
        *gpkdat=0x000000e0;    //GPKDAT=0x000000e0,GPKDAT[7:4]=1110,LED1点亮
        delay();
        *gpkdat=0x000000d0;    //GPKDAT=0x000000d0,GPKDAT[7:4]=1101,LED2点亮
        delay();
        *gpkdat=0x000000b0;    //GPKDAT=0x000000b0,GPKDAT[7:4]=1011,LED3点亮
 	delay();
        *gpkdat=0x00000070;    //GPKDAT=0x00000070,GPKDAT[7:4]=0111,LED4点亮
       delay();
        *gpkdat=0x00000000;    //GPKDAT=0x00000000,GPKDAT[7:4]=0000,4个LED全亮
	delay();
	}
	
	return 0;
}

