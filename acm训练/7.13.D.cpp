#include<stdio.h>
int main()
{
	int n,i,tmp;
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		if(tmp%2==1)
		{
			sum++;
		}
	}
	printf("%d",sum);
}
