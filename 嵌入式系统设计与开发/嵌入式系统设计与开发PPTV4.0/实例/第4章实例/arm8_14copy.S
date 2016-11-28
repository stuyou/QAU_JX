	IMPORT |Image$$RO$$Base|
	IMPORT |Image$$RO$$Limit|
	IMPORT |Image$$RW$$Base|
	IMPORT |Image$$RW$$Limit|
	IMPORT |Image$$ZI$$Base|
	IMPORT |Image$$ZI$$Limit|
	AREA STR,DATA,READWRITE
SRC_STR DCB "source",0
DES_STR SPACE 10
	AREA TEST,CODE,READONLY
	ENTRY
START
	LDR R0,=SRC_STR
	LDR R1,=DES_STR
	LDR R3,=|Image$$RO$$Limit|
	LDR R4,=|Image$$RW$$Base|
	CMP R3,R4	;若相等，则没必要进行RW的拷贝
	BEQ STRCOPY		;相等，直接进入字符串拷贝，跳过RW拷贝
	;=====RW COPY BEGIN=====
	LDR R5,=|Image$$RW$$Limit|
	SUB R5,R5,R4	;R5存放RW的长度
	MOV R6,#0		;循环变量
RWCOPY
	LDRB R7,[R3],#1
	STRB R7,[R4],#1
	ADD R6,R6,#1
	CMP R6,R5
	BNE RWCOPY
	;=====RW COPY END======
STRCOPY	
	LDRB R2,[R0],#1
	STRB R2,[R1],#1
	CMP R2,#0
	BNE STRCOPY
LOOP
	B LOOP
	END
	
	
