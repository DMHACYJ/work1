#include<stdio.h>
int main()
{
	int N,M,i,j,tmp;
	int a[10];
	int sum=0;
	while(scanf("%d", &N) != EOF)
	{
		scanf("%d %d",&N,&M);
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					tmp=a[j];
					a[j]=a[j+1];
					a[j+1]=tmp;
				}
			}
		}
		for(i=0;i<N;i++)
		{
			M=M-a[i];
			if(M<0)
			{
				break;
			}
			sum++;
		}
		printf("%d",sum);
		sum=0;
	}
}
