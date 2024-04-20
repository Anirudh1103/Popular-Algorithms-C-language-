#include<stdio.h>
#include<stdlib.h>
int V[50],indegree[50],stack[50],top=0,n,a[50][50],pos[50],i,j,k;
void main()
{
    printf("\n\t\t\t TOPOLOGICAL ORDER\n");
    printf("\n enter number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     pos[i]=0;
    printf("\n enter the adjacent matrix(1/0)\n");
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(i!=j)
         {
               printf("\n(%d,%d):",i,j);
               scanf("%d",&a[i][j]);
          }
               topological();
  }
 topological()
{
  for(i=1;i<=n;i++)
  indegree[i]=0;
  for(i=1;i<=n;i++)
  {
    int u;
    u=adjacent(i);
    while(u)
    {
      indegree[u]++;
      u=adjacent(i);
    }
}
for(i=1;i<=n;i++)
  pos[i]=0;
   for(i=1;i<=n;i++)
    if(indegree[i]==0)
      stack_insert(i);
      while(isempty()==0)
      {
         int w,u;
         w=stack_delete();
         V[++k]=w;
         u=adjacent(w);
         while(u)
           {
             indegree[u]--;
             if (indegree[u]==0) 
              stack_insert(u);
               u=adjacent(w);
          }
   }
if(k==n)
{
  printf("\n Topological sequence exit\n");
  for(i=1;i<=k;i++)
  printf("%d\t",V[i]);
}
else
  {
    printf("\n Topological sequence doesnot exit\n");
   }
}
adjacent(int i)
{
  for(j=pos[i]+1;j<=n;j++)
  if(a[i][j]==1)
   {
     pos[i]=j;
     return j;
    }
     pos[i]=n+1;
 return 0;
}
 stack_insert(int ele)
{
  stack[++top]=ele;
}
int stack_delete()
{
  return(stack[top--]);
} 
isempty()
{
 if (top==0)
return 1;
else 
  return 0;
}

