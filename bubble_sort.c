#include<stdio.h>
void main()
{
    int i,j,n,a[5],temp;
    printf("enter the number of array........");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
       printf("%d",a[i]);
    }
}
