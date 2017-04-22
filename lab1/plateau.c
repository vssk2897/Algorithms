#include<stdio.h>
int plateau(int[],int);
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
	printf("\nThe length of the longest Plateau is %d\n",plateau(a,n)+1);
}
int plateau(int a[],int n)
{
	int j,max=-1,length;
	length =0;
	for(j=0;j<n-1;++j)//Tricky part
	{
		if(a[j]==a[j+1])
		{
			length++;
		}
		else
		{
			length=0;	
		}
		if(length>max)
				max=length;
	}
	
	return max;
}
