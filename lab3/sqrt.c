#include<stdio.h>
int sqrt1(int);
int main()
{
	int x;
	printf("Enter the number : ");
	scanf("%d",&x);
	printf("\nThe Square root of the number is %d\n",sqrt1(x));
	return 0;
}

int sqrt1(int x)
{
	int res,lb,ub;
	if(x==0 || x==1)
		return x;
	lb=1;ub=x;
	while(lb<=ub)
	{
		int mid=lb+(ub-lb)/2;
		if(mid*mid==x)
			return mid;
		if(mid*mid<x)
		{
			lb=mid+1;
			res=mid;
		}	
		else
		{
			ub=mid-1;
		}
	}
	return res;	
}
