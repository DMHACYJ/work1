#include<stdio.h>
int main()
{
	int i,n,l,tmp;
	int j=0;
	int a[10000];
	int sum=0;
	while(~scanf("%d %d",&n,&l))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			if(tmp%2==0)
			{
				a[j]=tmp;
				j++;
			}
		}
		for(i=0;i<j-1;i++)
		{
			if((a[i]+a[i+1])==l&&a[i]!=-1&&a[i+1]!=-1)
			{
				a[i]=-1;
				a[i+1]=-1;
				sum++;
			}
		}
		if(sum)
		{
			printf("%d\n",sum);
		}
		else
		{
			printf("What a pity!!!\n");
		}
		sum=0;
		j=0;
	}
	return 0;
}
