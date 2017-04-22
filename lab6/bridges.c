#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int b[],int lb,int ub)
{
	int pivot=b[ub],i,j,t;
	i=lb-1;
	for(j=lb;j<ub;++j)
	{
		if(b[j]<=pivot)
		{
			i++;
			t=a[j];
			a[j]=a[i];
			a[i]=t;
			t=b[j];
			b[j]=b[i];
			b[i]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[ub];
	a[ub]=t;
	t=b[i+1];
	b[i+1]=b[ub];
	b[ub]=t;
	return i+1;
}

void quickSort(int a[],int b[],int lb,int ub)
{
	if(lb<=ub)
	{
		int q=partition(a,b,lb,ub);
		quickSort(a,b,lb,q-1);
		quickSort(a,b,q+1,ub);
	}
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

int main()
{
	int n,a[20],i,b[20];
	printf("Enter the No. of Inputs in the sequence : ");
	scanf("%d",&n);
	printf("\nEnter the Elements of the first sequence of cities : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the Elements of the Second sequence of cities : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&b[i]);
	}
	quickSort(a,b,0,n);
	printf("\nThe Maximum No. of bridges that can be built are %d\n",lis(b,n));
	return 0;
}	
