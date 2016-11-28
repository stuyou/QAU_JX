#include <stdio.h>
void my_strcpy(const char *src, char *dest){
char ch;
       __asm{
              loop:
                     ldrb ch, [src], #1
                     strb ch, [dest], #1
                     cmp ch, #0
                     bne loop
       }
} 
int main(){
       char *a="forget it and move on!";
       char b[64];
       my_strcpy(a, b);
       printf("original: %s", a);
       printf("copyed: %s", b);
       return 0;
} 
