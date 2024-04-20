#include<stdio.h>
#include<math.h>
void nqueen(int k,int n);
int place(int k,int i);
int count,x[20];

void main()
{
	int n;
	printf("Enter the number of queens:");
	scanf("%d",&n);
	nqueen(1,n);
	if(count==0)
		printf("No solution for %d queens\n",n);
	getchar();
}

void nqueen(int k,int n)
{
	int i,j,p,q;
	for(i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				count++;
				printf("Solution %d:\n",count);
				for(p=1;p<=n;p++)
				{
					for(q=1;q<=n;q++)
					{
						if(x[p]==q)
						{
						    printf("Q");
						}
						else
						{
						   printf("x");
						}
					}
					printf("\n");
					}
				}
			else
			{
			   nqueen(k+1,n);
			}
		}
	}
}


int place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
	{
		if(x[j]==i||(abs(x[j]-i)==abs(j-k)))
		return 0;
	}
	return 1;
}
															
