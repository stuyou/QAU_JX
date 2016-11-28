#include <stdio.h>

int main()
{
	int n=0;
	int sum_fac=0;
	int sum_add=0;
	int myfac=0;
	int i;
	printf("enter n,please:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		myfac=factorial(i);
		sum_fac=sum_fac+myfac;
	}

	sum_add=add(factorial(n),factorial(n-1));
	
	printf("1!+2!+...+n!=");
	prn(sum_fac);
	
	printf("(n-1)!+n!=");
	prn(sum_add);

	return 0;
}

