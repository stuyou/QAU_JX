/********************************************************
*Name:first_drv.c
*Desc: 第1个驱动程序，指定主设备号，手动创建设备节点，无硬件操作
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


static int first_drv_open(struct inode *inode,
                                             struct file *file)
{
	printk("first_drv_open\n");
	return 0;	
}

static ssize_t first_drv_write(struct file *file, 
	                                           const char __user *buf, 
	                                           size_t count, 
	                                           loff_t * ppos)
{
	printk("first_drv_write\n");
	return 0;
}

static struct file_operations first_drv_fops = {
    	.owner  =   THIS_MODULE,    
/* 这是一个宏，推向编译模块时自动创建的__this_module变量 */
    	.open   =   first_drv_open,     
	.write   =	  first_drv_write,	   
}; 

int first_drv_init(void)
{
 	register_chrdev(111, "firstdrv", &first_drv_fops);
	return 0;
}

void first_drv_exit(void)
{
 	unregister_chrdev(111, "firstdrv");
}

module_init(first_drv_init);
module_exit(first_drv_exit);

MODULE_AUTHOR("YHD");//驱动程序所有者
MODULE_DESCRIPTION("THE FIRST DRIVER");//描述信息
MODULE_LICENSE("GPL");//遵循的协议

