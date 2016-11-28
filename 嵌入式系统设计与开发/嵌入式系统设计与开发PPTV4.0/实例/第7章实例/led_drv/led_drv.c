/********************************************************
*Name:led_drv.c
*Desc: LED驱动程序，自动分配主设备号，自动创建设备节点
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2016-2-4
*Modify: 2016-4-11
*********************************************************/
#include <linux/miscdevice.h>
#include <linux/delay.h>
#include <asm/irq.h>
//#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <linux/string.h>
#include <linux/list.h>
#include <linux/pci.h>
#include <asm/uaccess.h>
#include <asm/atomic.h>
#include <asm/unistd.h>
#include <mach/map.h>
#include <mach/regs-clock.h>
#include <mach/regs-gpio.h>
#include <plat/gpio-cfg.h>
#include <mach/gpio-bank-e.h>
#include <mach/gpio-bank-k.h>
#include <linux/device.h>

static struct class *led_drv_class;
//static struct class_device	*first_drv_class_dev;

volatile unsigned long *gpkcon0=NULL;
volatile unsigned long *gpkdat=NULL;

static int led_drv_open(struct inode *inode,
                                             struct file *file)
{
	//printk("led_drv_open\n");
	//配置GPK4/5/6/7为输出功能
	*gpkcon0  &=  ~(0xffff<<16);//GPKCON0[31:16]清零
	*gpkcon0 |=  (0x1<<(4*4)) |(0x1<<(5*4))|(0x1<<(6*4))|(0x1<<(7*4));
		//配置GPK4/5/6/7为输出功能
	return 0;	
}

static ssize_t led_drv_write(struct file *file, 
	                                           const char __user *buf, 
	                                           size_t count, 
	                                           loff_t * ppos)
{
	//printk("led_drv_write\n");
	int val;
	copy_from_user(&val, buf, count);//用户空间到内核空间传递数据
	if(val==1)
		{
		//LED1~LED4全亮
		*gpkdat &= ~(0xf<<4);//GPKDAT[0:4]清零
		*gpkdat |= (0x0<<4);//输出低电平，LED点亮
		}
	else if(val == 0)
		{
		//LED1~LED4全灭
		*gpkdat &= ~(0xf<<4);//GPKDAT[0:4]清零
		*gpkdat |= (0xf<<4);//输出高电平，LED熄灭
		}
	
	return 0;
}

static struct file_operations led_drv_fops = {
    	.owner  =   THIS_MODULE,    
/* 这是一个宏，推向编译模块时自动创建的__this_module变量 */
    	.open   =   led_drv_open,     
	.write   =	  led_drv_write,	   
}; 

int major;
int led_drv_init(void)
{
 	major=register_chrdev(0, "leddrv", &led_drv_fops);

	led_drv_class = class_create(THIS_MODULE, "led_drv");
	 device_create(led_drv_class, NULL, MKDEV(major, 0), NULL, "myled_drv");
	//创建设备节点:/dev/myled_drv，主设备号为major，次设备号为0
	gpkcon0=(volatile unsigned long *)ioremap(0x7F008800,16);//ioremap第1个参数为起始地址，第2个参数为长度；
	gpkdat=gpkcon0+2;//这里加2实际上是加2个long型变量长度，加8个字节
	
	
	return 0;
}

void led_drv_exit(void)
{
 	unregister_chrdev(major, "leddrv");

	//class_device_unregister(first_drv_class_dev);
	device_destroy(led_drv_class,MKDEV(major, 0));
	class_destroy(led_drv_class);

	iounmap(gpkcon0);
}

module_init(led_drv_init);
module_exit(led_drv_exit);

MODULE_AUTHOR("YHD");//驱动程序所有者
MODULE_DESCRIPTION("THE LED DRIVER");//描述信息
MODULE_LICENSE("GPL");//遵循的协议

