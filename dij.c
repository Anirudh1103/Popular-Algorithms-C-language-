#include<stdio.h>
#define infinity 999

void dijkstra(int cost[10][10],int n,int src,int distance[],int p[])
{
	int v[10],min,u,i,j;
	for(i=1;i<=n;i++)
	{
		distance[i]=cost[src][i];
		v[i]=0;
		p[i]=src;
	}
	v[src]=1;
	for(i=1;i<=n;i++)
	{
		min=infinity;
		for(j=1;j<=n;j++)
		if(v[j]==0 && distance[j]<min)
		{
			min=distance[j];
			u=j;
		}
		v[u]=1;
		for(j=1;j<=n;j++)
		if(v[j]==0 && (distance[u]+cost[u][j])<distance[j])
		{
			distance[j]=distance[u]+cost[u][j];
			p[j]=u;
		}
	}
}

void main()
{
	int n,cost[10][10],d[10],p[10],i,j,src,sum;
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the cost matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			printf("(%d,%d):",i,j);
			scanf("%d",&cost[i][j]);
		}
	printf("\nEnter the source vertex:");
	scanf("%d",&src);
	dijkstra(cost,n,src,d,p);
	for(i=1;i<=n;i++)
	{
		j=i;
		while(j!=src)
		{
			printf("%d<---",j);
			j=p[j];
		}
		printf("%d=%d\n",j,d[i]);
	}
	getchar();
}

