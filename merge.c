#include<stdio.h>
#include<stdlib.h>
int merge_sort(int a[], int l, int h)
{
  int mid;
  if(l<h)
  {
    mid = (l+h)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,h);
    simple_merge(a,l,mid,h);
  }
}

simple_merge(int a[], int l, int mid, int h)
{
  int i=l,k=l,j=mid+1,c[20];
  while(i<=mid && j<=h)
  {
    if(a[i]<a[j])c[k++] = a[i++];
    else c[k++] = a[j++];
  }
  while(i<=mid)c[k++] = a[i++];
  while(j<=h)c[k++] = a[j++];
  for(i=l;i<=h;i++)a[i] = c[i];
}

void mainn()
{
  int i,n,a[20];
  printf("Enter the size of the array: ");
  scanf("%d",&n);
  printf("Enter the %d elements of the array: \n");
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  printf("Elements of the array  before sorting: \n");
  for(i=0;i<n;i++)printf("%d\t",&a[i]);
  merge_sort(a,0,n-1);
  printf("Elements of the array  after sorting: \n");
  for(i=0;i<n;i++)printf("%d\t",&a[i]);
}