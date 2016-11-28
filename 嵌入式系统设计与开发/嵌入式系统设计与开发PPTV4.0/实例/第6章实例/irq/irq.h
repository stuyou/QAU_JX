#ifndef __IRQ_H__
#define __IRQ_H__

#define	GPKCON0					(*(volatile unsigned long *)0x7F008800)
#define	GPKDAT 					(*(volatile unsigned long *)0x7F008808)
#define GPNCON     			(*((volatile unsigned long *)0x7F008830))
#define GPNDAT     			(*((volatile unsigned long *)0x7F008834))

#define EINT0CON0  			(*((volatile unsigned long *)0x7F008900))
#define EINT0MASK  			(*((volatile unsigned long *)0x7F008920))
#define EINT0PEND  			(*((volatile unsigned long *)0x7F008924))

#define VIC0INTENABLE  	(*((volatile unsigned long *)0x71200010))
#define VIC0IRQSTATUS  (*((volatile unsigned long *)0x71200000))
#define VIC0FIQSTATUS  (*((volatile unsigned long *)0x71200004))
#define VIC0RAWINTR    (*((volatile unsigned long *)0x71200008))
#define VIC0INTSELECT  (*((volatile unsigned long *)0x7120000c))
#define VIC0INTENCLEAR (*((volatile unsigned long *)0x71200014))
#define VIC0PROTECTION (*((volatile unsigned long *)0x71200020))
#define VIC0SWPRIORITYMASK (*((volatile unsigned long *)0x71200024))
#define VIC0PRIORITYDAISY  (*((volatile unsigned long *)0x71200028))

#define VIC0ADDRESS        (*((volatile unsigned long *)0x71200f00))
#define VIC0VECTADDR0      (*((volatile unsigned long *)0x71200100))


#define	GPK4_OUT		(0x1U<<(4*4))
#define	GPK5_OUT		(0x1U<<(5*4))
#define	GPK6_OUT		(0x1U<<(6*4))
#define	GPK7_OUT		(0x1U<<(7*4))

#define	LED_ALL_OFF		0xF
#define	LED_ALL_ON		0x0
#define	LED1_ON			(~(0X1U<<0))
#define	LED2_ON			(~(0X1U<<1))
#define	LED3_ON			(~(0X1U<<2))
#define	LED4_ON			(~(0X1U<<3))

#endif
