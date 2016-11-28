	AREA TEST,CODE,READONLY ;声明代码段Example
	ENTRY                      ;程序入口
Start
	MOV  R0,#2                 ;将R0赋初值2 
	MOV  R1,#5                 ;将R1赋初值5
	ADD  R5,R0,R1              ;将R0和R1内的值相加并存入R5
	CMP  R5,#10                
	BEQ  DOEQUAL               ;若R5为10，则跳转到DOEQUAL标签处
WAIT    
	CMP  R0,R1 
	ADDHI R2,R0,#10            ;若R0 >R1 则R2=R0+10
	ADDLS R2,R1,#5             ;若R0<=R2 则R2=R1+5
DOEQUAL
	ANDS R1,R1,#0x80           ;R1=R1& 0x80,并设置相应标志位
	BNE  WAIT                  ;若R1 的d7位为1则跳转到WAIT标签
OVER
	END 
