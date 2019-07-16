#include<stdio.h>
int main()
{
	int n,i;
	int result=4;
	int ans=1000000009;
	while(scanf("%d", &n) != EOF)
	{
		do
		{
			switch(n)
			{	
			case 2:
				printf("%d\n",result);
				break;
			default:
				for(i=3;i<=n;i++)
				{
					result=(result%ans)*3;
				}
				printf("%d\n",result%ans);
				break;
			}
		}while(0);
		result=4;
	}
}
