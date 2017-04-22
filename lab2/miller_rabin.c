#include<stdio.h>
#include<stdlib.h>
int power(int,int);
int millerRabin(int,int);
int main()
{
	int p,k;
	printf("Enter the number which is to be tested : ");
	scanf("%d",&p);
	printf("\nEnter the value of the iterator : ");
	scanf("%d",&k);
	if(millerRabin(p,k)==1)
		printf("\nThe number %d is prime\n",p);
	else		
		printf("\nThe number %d is not prime\n",p);
	return 0;	
}

int millerRabin(int p,int k)
{
	int a,s,mod,temp,i;
	if(p<2)
		return 0;
	if(p!=2 && p%2==0)
		return 0;
	s=p-1;
	while(s%2==0)
		s=s/2;	//Stops when we get first odd factor
	for(i=0;i<=k;++i)
	{
		a=rand()%(p-1)+1;
		temp=s;
		mod=power(a,temp)%p;
	
		while(temp!=p-1 && mod!=1 && mod!=p-1)
		{
			mod=(mod*mod)%p;
			temp=temp*2;
		}		
		if(mod!=p-1 && temp%2==0)
			return 0;
	}	
	return 1;	
}

int power(int b,int e)
{
	int temp;
	if(e==0)
		return 1;
	else
	{
		temp=power(b,e/2);
		if(e%2==0)
			return temp*temp;
		else
			return b*temp*temp;	
	}	
}
