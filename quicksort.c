#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
} 
int partition(int a[],int l,int h)
{
	int pivot = a[l];
	int i=l;
	int j=h;
	do
	{
		do
		{	
			i++;
		}while(a[i]<=pivot);
		do
		{
			j--;
		}while(a[j]>pivot);
		if(i<j)
		{	
			swap(&a[i],&a[j]);
		}
	}while(i<j);

	swap(&a[l],&a[j]);
	return j;
}
void quicksort(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}
int main()
{
	int n,i,h;
	scanf("%d",&n);
	h=n;
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,h);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}