#include <stdio.h>

int main()
{
	int n=0;
	int myfac=0;
	printf("enter n,please:");
	scanf("%d",&n);

	myfac=factorial(n);
	
	printf("n!=");
	prn(myfac);

	return 0;
}

