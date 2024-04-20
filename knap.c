#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int knapsack(int n,int w[10],int p[10],int m,int v[20][20])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
				v[i][j]=0;
			else
				if(j<w[i])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
		}
	}
return 0;
}

int solution_vector(int n,int m,int w[10],int v[20][20])
{
	int i,j,k[10];
	printf("optimal solution is %d\n",v[n][m]);
	for(i=1;i<=n;i++)
		k[i]=0;
	i=n;
	j=m;
	while(i!=0 && j!=0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			k[i]=1;
			j=j-w[i];
		}
		i--;
	}
	printf("the solution vector is\n");
	for(i=1;i<=n;i++)
		printf("%d\t",k[i]);
	return 0;
}

int max(int x,int y)
{
	return (x>y)?x:y;
}

void main()
{
	int n,m,p[10],w[10],i,j,v[20][20];
	printf("knapsack problem\n");
	printf("Enter the number of objects\n");
	scanf("%d",&n);
	printf("Enter the weight of the objects\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("Enter the profit of the objects\n");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("Enter the Max capacity\n");
	scanf("%d",&m);
	knapsack(n,w,p,m,v);
	printf("knapsack table\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
	solution_vector(n,m,w,v);
	getchar();
}

