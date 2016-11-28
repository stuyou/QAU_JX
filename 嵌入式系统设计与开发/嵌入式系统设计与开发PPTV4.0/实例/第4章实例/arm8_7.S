	AREA TEST,CODE,READONLY
	ENTRY
START
	MOV             R0,#0x400000
	LDR              R1,[R0]        ;把第一个数存入R1
	LDR              R2,[R0,#4]   ;把第二个数存入R2
	CMP              R1,R2          ;两个数进行比较
	MOVHI  R1,#1          ;R1>R2,
	MOVLO R1,# -1        ;R1<R2
	MOVEQ R1,#0          ;R1=R2
	STR        R1,[R0,#8]  ;保存结果到0X400008
STOP
       MOV R0, #0x18
       LDR R1, =0x20026
       SWI 0x123456      
       END