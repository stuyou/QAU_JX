/********************************************************
*Name: start.S
*Desc: S3C6410裸机中断程序的初始代码。使用VIC_port模式
*处理中断，当按下key1~key4时，分别点亮LED1~LED4
*基于友善之臂tiny6410开发板
*Author: yoyoba(stuyou@126.com)
*Date: 2014-6-4
*Modify: 2016-4-11
*********************************************************/

.global _start
.global do_irq
.extern key_isr

_start:
	//把外设基地址告诉CPU
	ldr r0, =0x70000000
   	orr r0, r0, #0x13
   	mcr p15,0,r0,c15,c2,4

	//开启S3C6410的中断VIC_port功能
	//开启此功能，发生中断时，CPU会自动
	//跳到ISR，执行ISR。这种跳转操作
	//是由硬件自动执行的
 	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#(1<<24)
	mcr p15,0,r0,c1,c0,0
    
	// 关看门狗
	ldr r0, =0x7E004000
	mov r1, #0
	str r1, [r0]
	
	// 设置栈
	ldr sp, =0x0c002000

	//初始化LED
	bl led_init
	// 初始化irq
	bl irq_init

	//开启中断总开关，设置CPSR的I位为0
	mrs r0,cpsr
	bic r0,r0,#0x80
	msr cpsr_c,r0

	bl main//跳转到主函数
	
//do_irq函数是中断服务函数，首先保存现场
//然后跳转到key_press按键判断程序
//最后恢复现场
do_irq:
	ldr sp, =0x54000000	//发生IRQ中断后，CPU自动切换到IRQ模式下
					//sp是分组寄存器，因此关看门狗后设置的
					//栈不能使用，这里要重新设置栈，供保存、
					//恢复现场使用
					
	sub lr, lr, #4		//lr存放的是发生中断时那条指令的下一条指令
					//恢复现场时，保证能正常返回到主程序，
					//这里lr应减去4
					
	stmdb sp!, {r0-r12, lr}  //保存现场
	bl key_isr  			//跳到key_isr程序，
	ldmia sp!, {r0-r12, pc}^ //恢复现场，^表示把SPSR恢复到CPSR
	
halt:
	b halt
