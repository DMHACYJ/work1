#include<stdio.h>
#include<string.h>
int main()
{
	int t,n,i,j,k;
	char tmp[100];
	int a[100];
	while(scanf("%d %d",&t,&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		while(t--)
		{
			scanf("%s",tmp);
			if(tmp[0]=='l')
			{
				scanf("%d",&i);
				for(k=i;k<n;k++)
				{
					a[k]=a[k+1];
				}
				n--;
			}
			else if(tmp[0]=='i')
			{
				scanf("%d %d",&i,&j);
				for(k=n+1;k>i;k--)
				{
					a[k]=a[k-1];
					printf("1");
				}
				
				a[k]=j;
				n++;
				for(i=1;i<=n;i++)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
			}
		}
		
	}
	return 0;
}

