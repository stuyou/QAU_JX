	EXPORT strcpy
	AREA FUN,CODE,READONLY
strcpy
	LDRB a3,[a2],#1	;a2=R1,a3=R2参数传递
	STRB a3,[a1],#1	;a1=R0，参数传递
	CMP a3,#0
	BNE strcpy
	MOV PC,LR
	END