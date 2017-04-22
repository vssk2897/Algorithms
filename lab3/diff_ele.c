#include<stdio.h>
void diffEle(int[],int,int);
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
	diffEle(a,0,n);
}
void diffEle(int a[],int lb,int ub)
{
	if(lb<=ub)
	{
		int mid = lb+(ub-lb)/2;
		if(mid%2==0)
		{
			if(a[mid]==a[mid-1])
			{
				diffEle(a,lb,mid-1);
				diffEle(a,mid+1,ub);
			}	
			else
			{
				printf("\nThe different element is %d\n",a[mid]);
				return;
			}		
		}
		else
		{
			if(a[mid]==a[mid+1])
			{
				diffEle(a,lb,mid-1);
				diffEle(a,mid+1,ub);
			}	
			else
			{
				printf("\nThe different element is %d\n",a[mid]);
				return;
			}
		}
	}
}
