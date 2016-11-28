#include <stdio.h>

int mysum2(int a,int b);
int mysum3(int a,int b,int c);
int mysum4(int a, int b,int c,int d);

int main()
{
	int a=10,b=20,c=30,d=40;
	int x=1,y=2,z=3;
	int sum2,sum3,sum4;
	sum2=sum3=sum4=0;
	sum2=mysum2(a,x);
	sum3=mysum3(a,b,y);
	sum4=mysum4(c,d,y,z);
	printf("sum2=%d,sum3=%d,sum4=%d\n",sum2,sum3,sum4);
	return 0;
}
