	AREA TEST,CODE,READONLY ;声明代码段Example
	ENTRY                      ;程序入口
Start
	MOV  R1,#0                 ;将R1赋初值0
LOOP     
	ADD  R1,R1,#1
	CMP  R1,#10
	BCC  LOOP                  ;R1小于10则执行跳转到LOOP处执行循环，即R1从0到10后退出循环
	END 
