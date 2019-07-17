#include<stdio.h>
long long int fun(int n)
{
	if(n==1)
	{
		return 1;
	}
	return n*fun(n-1);
}
int main()
{
	int n;
	long long int y;
	while(scanf("%d",&n)!=EOF)
	{
		y=fun(n);
		printf("%lld\n",y);
	}
	return 0;
}
