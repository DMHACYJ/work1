#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100+8;
char oil[maxn][maxn];
int vis[maxn][maxn];
int sum;
int n,m;
void dfs(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m) return;
	if(oil[x][y]!='@'||vis[x][y]) return;
	vis[x][y]=1;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			if(i||j)
			{
				dfs(x+i,y+j);
			}
		}
	}
}

int main()
{
	string temp;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		memset(vis,0,sizeof(vis));
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",oil[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(oil[i][j]=='@'&&!vis[i][j])
				{
					dfs(i,j);
					sum++;
				}
			}	
		}
		printf("%d\n",sum);
	}
	return 0; 
} 
