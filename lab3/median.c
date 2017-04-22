#include<stdio.h>
int median(int[],int);
int medianOfArrays(int[],int[],int);
int max(int,int);
int min(int,int);
int main()
{
	int n,a[20],i,b[20];
	printf("Enter the No. of Inputs in the sequence : ");
	scanf("%d",&n);
	printf("\nEnter the Elements of the first sequence in sorted order : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the Elements of the second sequence in sorted order : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&b[i]);
	}
	printf("\nThe median of the two arrays is %d\n",medianOfArrays(a,b,n));
	return 0;
}
int medianOfArrays(int a[],int b[],int n)
{
	int m1,m2;
	if(n==1)
		return (a[0]+b[0])/2;
	if(n==2)
		return ((max(a[0],b[0])+min(a[1],b[1]))/2);	
	m1=median(a,n);
	m2=median(b,n);
	if(m1==m2)
		return m1;
	if(m1<m2)
	{
		if(n%2==0)
			return medianOfArrays(a+n/2-1,b,n-n/2+1);
		return medianOfArrays(a+n/2,b,n-n/2);	
	}		
	else
	{
		if(n%2==0)
			return medianOfArrays(b+n/2-1,a,n-n/2+1);
		return medianOfArrays(b+n/2,a,n-n/2);
	}
}
int median(int a[],int n)
{
	if(n%2==0)
		return ((a[n/2]+a[n/2-1])/2);
	return a[n/2];
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;	
}
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;	
}
