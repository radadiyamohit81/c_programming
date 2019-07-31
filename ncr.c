#include<stdio.h>
int fact(int n)
{
	if(n==0)
	return 1;
	else
	return n*fact(n-1);
}
int ncr(int n,int r)
{
	int num,den;
	num=fact(n);
	den=fact(r)*fact(n-r);
	return num/den;
}		
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	printf("%d",ncr(n,r));
	return 0;
}