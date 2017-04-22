#include<stdio.h>
int gcd(int,int);
int GCD(int[],int);
int main()
{
	int n,a[20],i;
	printf("Enter the No. of Inputs in the sequence : ");
	scanf("%d",&n);
	printf("\nEnter the Elements of the sequence : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nThe GCD of the Elements is %d\n",GCD(a,n));
}
int GCD(int a[],int n)
{
	int ans=a[n-1],i;
	for(i=n-2;i>=0;--i)
	{
		if(ans==1)
			return 1;
		ans=gcd(ans,a[i]);
	}
	return ans;
}
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);	
}
