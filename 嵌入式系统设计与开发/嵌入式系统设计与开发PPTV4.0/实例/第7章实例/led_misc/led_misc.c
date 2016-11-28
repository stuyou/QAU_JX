/********************************************************
*Name:led_misc.c
*Desc: LED杂项设备(misc)驱动程序，自动分配主设备号，自动创建设备节点
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

#define DEVICE_NAME "myled_misc"

//volatile unsigned long *gpkcon0=NULL;
//volatile unsigned long *gpkdat=NULL;

static int led_misc_open(struct inode *inode, 
							struct file *file)
{
	//printk("led_misc_open\n");
	//配置GPK4/5/6/7为输出功能
	unsigned tmp;
	
	tmp = readl(S3C64XX_GPKCON);//读GPKCON0寄存器的值	
	
	tmp &=  ~(0xffffU<<16);//清零
	tmp |= (0x1<<(4*4)) |(0x1<<(5*4))|(0x1<<(6*4))|(0x1<<(7*4));//配置为输出
	
	writel(tmp, S3C64XX_GPKCON);//写入GPKCON0寄存器
	
	//*gpkcon0  &=  ~(0xffff<<16);//GPKCON0[31:16]清零
	//*gpkcon0 |=  (0x1<<(4*4)) |(0x1<<(5*4))|(0x1<<(6*4))|(0x1<<(7*4));
		//配置GPK4/5/6/7为输出功能
	return 0;	
}

static long led_misc_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    switch(cmd) {
    unsigned int tmp;
    case 0:
    case 1:
    	if(arg > 4) return -EINVAL;
			tmp = readl(S3C64XX_GPKDAT);		//read GPK io data
			tmp &= ~(1 << (4 + arg));		//clear bit
      tmp |=  ((!cmd) << (4 + arg));		//set bit with cmd
      writel(tmp, S3C64XX_GPKDAT);		//write data register
      return 0;
    default:
        return -EINVAL;
    }
}

static struct file_operations led_misc_fops = {
    .owner = THIS_MODULE,
    .open = led_misc_open,
    .unlocked_ioctl = led_misc_ioctl,
    //linux 2.6内核中iotcl函数原型为:
    //long (* unlocked_ioctl)(struct *file,unsigned int,unsigned long)
    //与2.4内核中的不同 
};

/*misc device：杂项设备，即主设备号为10的特殊字符设备*/
static struct miscdevice led_misc_misc = {  
    //次设备号，注意不要与/proc/misc中已有杂项设备次设备号冲突
    .minor = MISC_DYNAMIC_MINOR,	//MISC_DYNAMIC_MINOR来动态获取次设备号
    .name = DEVICE_NAME,		//设备名称,用来创建/dev/myled_misc设备节点
    .fops = &led_misc_fops,
};


int led_misc_init(void)
{
	//gpkcon0=(volatile unsigned long *)ioremap(0x7F008800,16);//ioremap第1个参数为起始地址，第2个参数为长度；
	//gpkdat=gpkcon0+2;//这里加2实际上是加2个long型变量长度，加8个字节
	/* 该函数会自动创建设备节点，即设备文件 */
	misc_register(&led_misc_misc);
	printk (DEVICE_NAME"\tinitialized\n");
	
	return 0;
}

void led_misc_exit(void)
{
    misc_deregister(&led_misc_misc);
}

module_init(led_misc_init);
module_exit(led_misc_exit);


MODULE_AUTHOR("YHD");//驱动程序所有者
MODULE_DESCRIPTION("THE LED_MISC DRIVER");//描述信息
MODULE_LICENSE("GPL");//遵循的协议