#include<stdio.h>
void quickSort(int[],int,int);
int partition(int[],int,int);
int binarySearch(int[],int,int,int);
int main()
{
	int n,a[20],i,sum,diff;
	printf("Enter the No. of Inputs in the sequence : ");
	scanf("%d",&n);
	printf("\nEnter the Elements of the sequence : ");
	for(i=0;i<n;++i)
	{
		printf("\n\tElement [%d] : ",i+1);
		scanf("%d",&a[i]);
	}
	quickSort(a,0,n);
	printf("\nEnter the value of the sum : ");
	scanf("%d",&sum);
	for(i=0;i<n;++i)
	{
		if(sum>a[i])
			diff=sum-a[i];
		else
			diff=a[i]-sum;
		if(binarySearch(a,0,n-1,diff)==1)
			printf("\nOne of the possible combinations is %d + %d = %d\n",a[i],diff,sum);		
	}
	
}
//Tricky Quick Sort aaa..............????????
//QuickSort Thallipogathe
void quickSort(int a[],int lb,int ub)
{
	if(lb<=ub)
	{
		int q=partition(a,lb,ub);
		quickSort(a,lb,q-1);
		quickSort(a,q+1,ub);
	}
}

int partition(int a[],int lb,int ub)
{
	int pivot,t,i,j;
	pivot=a[ub];
	i=lb-1;
	for(j=lb;j<ub;++j)
	{
		if(a[j]<=pivot)
		{
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[ub];
	a[ub]=t;
	return i+1;
}

int binarySearch(int a[],int lb,int ub,int key)
{
	int found=0;
	if(lb<=ub)
	{
		int mid= lb + (ub-lb)/2;
		if(key==a[mid])
		{
			found=1;
		}
		else
		{
			if(key>a[mid])
				found=binarySearch(a,mid+1,ub,key);
			else	
				found=binarySearch(a,lb,mid-1,key);
		}
	}
	return found;
}
