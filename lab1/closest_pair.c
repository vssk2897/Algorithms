//T(n)=O(nlog(n))
#include<stdio.h>
//Yeno vaanilay maaruthey; malithuli poguthey; maarbin vegam kuduthey; manamo yedo solla varthai thedithey
void quickSort(int[],int,int);
int partition(int[],int,int);
void closestPair(int[],int);
int abso(int,int);
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
	quickSort(a,0,n);
	closestPair(a,n);
}
void quickSort(int a[],int lb,int ub)
{
	if(lb<=ub)
	{
		int q=partition(a,lb,ub);
		quickSort(a,lb,q-1);
		quickSort(a,q+1,ub);
	}
}
//kannelaam quickSort da nilkindrai ; vizhin mei naan kobam konden imai moodidu endren
int partition(int a[],int lb,int ub)
{
	int pivot=a[ub],i,j,t;
	i=lb-1;
	for(j=lb;j<ub;++j)
	{
		if(a[j]<=pivot)
		{
			i++;
			t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	t=a[i+1];
	a[i+1]=a[ub];
	a[ub]=t;
	return i+1;
}

void closestPair(int a[],int n)
{
	int i,min[20],mink,index;
	for(i=0;i<n-1;++i)
	{
		min[i]=abso(a[i],a[i+1]);
	}
	mink=9999;
	for(i=0;i<=n-1;++i)
	{
		if(min[i]<mink)
		{
			index=i;
			mink=min[i];
		}	
	}
	printf("\nThe Closest Pair would be %d & %d\n",a[index],a[index+1]);
}

int abso(int x,int y)
{
	if(x>y)
		return x-y;
	return y-x;	
}
