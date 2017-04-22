#include<stdio.h>
int horner(int[],int,int);
int main()
{
	int a[10],x,i,n;
	printf("Enter the degree of the polynomial : ");
	scanf("%d",&n);
	n+=1;
	printf("\nEnter the coefficients of the polynomial : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tCoeff of x[%d] : ",n-i-1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value of x : ");
	scanf("%d",&x);
	printf("\nThe value of the polynomial is %d\n",horner(a,n,x));
	return 0;
}
int horner(int a[],int n,int x)
{
	int ans=a[0],i;
	for(i=1;i<n;++i)
	{
		ans=ans*x+a[i];
	}
	return ans;
}
