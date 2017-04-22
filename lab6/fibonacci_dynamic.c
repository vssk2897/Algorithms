#include<stdio.h>
int main()
{
	int n,a[20],i;
	a[0]=0;a[1]=1;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	for(i=2;i<n;++i)
	{
		a[i]=a[i-1]+a[i-2];
	}
	printf("\nThe %dth fibonacci number is %d\n",n,a[n-1]);
	return 0;
}
