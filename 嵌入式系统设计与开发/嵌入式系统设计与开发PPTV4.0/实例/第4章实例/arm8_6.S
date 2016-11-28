	AREA TEST,CODE,READONLY
	ENTRY
START
	MOV             R0,#0x400000
	MOV             R1,#0
LP
	LDRB            R2,[R0,R1]
	CMP              R2,#0x61
	BLO              NEXT		;若R2<#0x61,跳转到NEXT
	CMP R2,#0x7B    			;0x61---0x7A为小写字母的ASCII
	SUBLO   R2, R2,#0x20		;若R2<#0X7B，则R2-#0X20(十进制32)转成大写字母ASCII
	STRB R2,[R0,R1]
NEXT
	ADD             R1, R1,#1
	CMP              R1,#100
	BNE              LP
	END