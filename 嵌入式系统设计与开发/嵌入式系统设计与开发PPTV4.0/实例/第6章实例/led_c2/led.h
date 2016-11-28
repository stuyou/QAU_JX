#ifndef __LED_H__
#define __LED_H__

#define	GPKCON0	(*(volatile unsigned long *)0x7F008800)
#define	GPKDAT 		(*(volatile unsigned long *)0x7F008808)

#define	GPK4_OUT		(0x1U<<(4*4))
#define	GPK5_OUT		(0x1U<<(5*4))
#define	GPK6_OUT		(0x1U<<(6*4))
#define	GPK7_OUT		(0x1U<<(7*4))

#define	LED_ALL_OFF		0xF
#define	LED_ALL_ON			0x0
#define	LED1_ON			(~(0X1U<<0))
#define	LED2_ON			(~(0X1U<<1))
#define	LED3_ON			(~(0X1U<<2))
#define	LED4_ON			(~(0X1U<<3))
#endif