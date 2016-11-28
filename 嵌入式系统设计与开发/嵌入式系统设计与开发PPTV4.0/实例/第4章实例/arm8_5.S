num EQU      10
 
       AREA  BlockData,DATA            ; 声明数据段
src   DCD      0,1,2,3,4,5,6,7,8,9                  ; 定义十个数
dst   SPACE    10*4
 
       AREA    TEST, CODE,READONLY                  ; 声明代码段
       ENTRY
 
START
       LDR R1, =src                      
       LDR R2,=dst
       MOV R3,#num
      
LOOP
       LDR R0, [R1], #4
       STR R0, [R2], #4
       SUBS R3, R3, #1
       BNE LOOP
     
STOP
       MOV R0, #0x18
       LDR R1, =0x20026
       SWI 0x123456      
       END