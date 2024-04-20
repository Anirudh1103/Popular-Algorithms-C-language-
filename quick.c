#include<stdio.h>
#include<stdlib.h>
void qs(int a[50],int l,int r);
void main()
 {
  int a[20],i,n;
  printf("enter the size of arrays \n");
  scanf("%d",&n);
  printf("enter the elements of array:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  qs(a,0,n-1);
   printf("\nsorted element are:\n");
   for(i=0;i<n;i++)
   printf("%d\t",a[i]);
  }
void qs(int a[50],int l,int r)
{
 int j;
if(l<r)
{
 j=partition(a,l,r);
 qs(a,l,j-1);
 qs(a,j+1,r);
}
}
int partition(int a[50],int l,int h)
{
 int v=a[l],i=1,j=h+1,temp;
while(i<=j)
{
do
i++;
while(v>=a[i]);
do
j--;
while(v<a[j]);
if(i<j)
{
 temp =a[i];
 a[i]=a[j];
 a[j]=temp;
}
}
temp=a[l];
a[l]=a[j];
a[j]=temp;
return(j);
}

