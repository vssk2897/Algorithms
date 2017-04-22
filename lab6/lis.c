#include<stdio.h>
#include<stdlib.h>
int lis(int[],int);
int main()
{
	int a[50],n,i;
	printf("Enter the no. of elements in the sequence : ");
	scanf("%d",&n);
	printf("Enter the elements of the sequence : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	printf("The value of Longest Increasing Subsequence is %d\n",lis(a,n));
} 
int lis(int a[],int n)
{
	int *dp,max=-1,i,j;
	dp=(int *)malloc(sizeof(int)*n);
	dp[0]=1;
	for(i=1;i<n;++i)
	{
		dp[i]=1;
		for(j=0;j<i;++j)
		{
			if(a[i]>a[j])
			{
				if(dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
				}
			}
		}
	}
	for(i=0;i<n;++i)
	{
		if(dp[i]>max)
			max=dp[i];
	}
	return max;
}
