	AREA TEST,CODE,READONLY ;声明代码段Example
	ENTRY                      ;程序入口
Start 
	MOV  R0,#0                 ;设置实参,将传递给子程骗子的实参存放在r0和r1内
	MOV  R1,#10
	BL   ADD_SUM               ;调用子程序ADD_SUM
	B    OVER                  ;跳转到OVER标号处，进入结尾
ADD_SUM
	ADD  R0,R0,R1              ;实现两数相加
	MOV  PC,LR                 ;子程序返回，R0内为返回的结果
OVER
	END
