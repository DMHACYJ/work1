#include<stdio.h>
int main()
{
	
	int i;
	long long int f[10000];
	f[0]=1;
	f[1]=1;
	for(i=2;i<10000;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]<0)
		{
			printf("%lld",f[i-1]);
			break;
		}
	}
}
