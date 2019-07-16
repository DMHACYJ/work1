#include<stdio.h>
int main()
{
	int n,m,l,k,i,j,z,x;
	int x1,x2,z1,y1,y2,z2;
	char a[50][50][50]={'0'};
	int sum=0;
	while(~scanf("%d %d %d %d",&n,&m,&l,&k))
	{
		if(n==0&&m==0&&l==0&&k==0) 
		{
			break;
		}
		for(x=0;x<k;x++)
		{
			scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
			for(i=x1;i<=x2;i++)
			{
				for(j=y1;j<=y2;j++)
				{
					for(z=z1;z<=z2;z++)
					{
						a[i][j][z]='1';
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				for(z=1;z<=l;z++)
				{
					if(a[i][j][z]=='1')
					{
						sum++;
					}
				}
			}
		}
		printf("%d\n",sum);	
		sum=0;
	}
}
