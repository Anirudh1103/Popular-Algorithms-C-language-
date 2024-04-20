#include<stdio.h>
#include<string.h>
#define max 256

int horspool(char *,char *);
int t[max];
void shiftable(char []);

int main()
{
	char src[max],pat[max];
	int pos;
	printf("Enter the source string:");
	gets(src);
	printf("Enter the pattern string:");
	gets(pat);
	pos=horspool(src,pat);
	if(pos==-1)
		printf("pattern not found\n");
	else
		printf("pattern found at %d\n",pos+1);
	getchar();
}

void shiftable(char p[])
{
	int m,index,i,j;
	m=strlen(p);
	for(i=0;i<max;i++)
		t[i]=m;
		for(j=0;j<m-1;j++)
		{
			index=(p[j]-'0');
			t[index]=m-1-j;
		}
}

int horspool(char s[],char p[])
{
	int i,n,m,index,k=0;
	n=strlen(s);
	m=strlen(p);
	shiftable(p);
	i=m-1;
	while(i<n)
	{
		while((k<m)&&(p[m-1-k]==s[i-k]))
			k++;
		if(k==m)
			return(i-m+1);
		else
		{
			index=(s[i]-'0');
			i=i+t[index];
		}
	}
	return -1;
}
