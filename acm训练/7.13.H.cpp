#include<stdio.h>
int main()
{
	int map[100][100];
	int n,m,i,j,sum=0,result;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if((i+j)%2==0)
			{
				map[i][j]='0';
				sum++;
			}
			else
			{
				map[i][j]='1';
			}
		}
	}
	if(n==1||m==1) 
	{
		result=(sum-1)*3;
	}
	else
	{
		result=4+(sum-2)*3;	
	}
	printf("%d",result);
}
