#include<stdio.h>
void bottomupheap(int h[],int n)
{
	int i,j,k,v,heap;
	for(i=n/2;i>=1;i--)
	{
		k=i;
		v=h[k];
		heap=0;
		while((heap==0)&&(2*k<=n))
		{
			j=2*k;
			if(j<n)
			{
				if(h[j]<h[j+1])
				{
					j++;
				}
			}
		if(v>=h[j])
		{
			heap=1;
		}
		else
		{
			h[k]=h[j];
			k=j;
		}
	}
		h[k]=v;
	}
}

void heapsort(int h[],int n)
{
	int temp,i;
	for(i=n;i>=1;i--)
	{
		bottomupheap(h,i);
		temp=h[1];
		h[1]=h[i];
		h[i]=temp;
	}
}

void main()
{
	int h[100],n,i;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i=1;i<=n;i++)
	{
		h[i]=rand()%100;
		printf("%d\t\n",h[i]);
	}
	heapsort(h,n);
	printf("the sorted array is:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",h[i]);
}
