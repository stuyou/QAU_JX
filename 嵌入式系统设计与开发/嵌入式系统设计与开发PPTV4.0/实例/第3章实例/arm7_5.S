	AREA TEST,CODE,READONLY
	ENTRY
START	MOV R0,#0			;初始化R0，作为循环计数器
		MOV R1,#1			;R1=1，内存区域的初始化值
		LDR R2,=0X3000		;R2存放内存区域的起始地址
INIT	STR R1,[R2],#4		;把R1的内容存放到[R2]指向的地址，并使R2+4
		ADD R0,R0,#4		;循环变量增加4，SRT是按字存的，所以这里加4
		CMP R0,#0X40		;比较循环变量R0，如果不为0X40，内存初始化没结束，跳转到标号为INIT的地方继续初始化
		BNE INIT			;跳转到INIT，循环
		LDR R1,=0X4000
		LDR R2,=0X3000
		MOV R0,#0
CP		LDR R3,[R2],#4
		STR R3,[R1],#4
		ADD R0,R0,#4
		CMP R0,#0X40
		BNE CP
	END
;如果使用LDM和STM指令，如何改写这段程序？