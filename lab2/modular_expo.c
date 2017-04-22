#include<stdio.h>
int power(int,int);
int main()
{
	int base,exp,n,pow;
	printf("Enter the value of base : ");
	scanf("%d",&base);
	printf("\nEnter the value of the Exponent : ");
	scanf("%d",&exp);
	printf("\nPlease Enter the value of n : ");
	scanf("%d",&n);
	pow=(power(base,exp));
	printf("\nThe modular Exponentiation of (%d^%d)mod(%d) is %d\n",base,exp,n,pow%n);
}
int power(int base,int exp)
{
	int ans=1,temp;
	if(exp==0)
		return 1;
	else
	{
		temp=power(base,exp/2);
		if(exp%2==0)
			ans=temp*temp;
		else
			ans=base*temp*temp;	
	}	
	return ans;
}
