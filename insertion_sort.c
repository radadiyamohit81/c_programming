#include<stdio.h>
void main()
{
   int n,i,j,a[5],temp;
   printf("enter the number of array");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   for( int i = 0 ;i < n ; i++ )
   {
      temp = a[ i ];
      j = i;
      while(  j > 0  && temp < a[ j -1])
      {
       a[ j ] = a[ j-1];
       j= j - 1;
      }
      a[ j ] = temp;
   }
   for(i=0;i<n;i++)
   {
       printf("%d",a[i]);
   }
}
