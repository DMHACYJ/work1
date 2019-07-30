#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1005;
int dis[maxn];
int mp[maxn][maxn];
int check[maxn];

int dijkstra(int n)
{
	memset(check,0,sizeof(check));
	fill(dis,dis+maxn,INF);
	for(int i=1;i<=n;i++)
	{
		dis[i]=mp[1][i];
	}
	int minx,pos;
	dis[1]=0;
	check[1]=1;
	for(int i=1;i<n;++i)
	{
		minx=INF;
		for(int j=1;j<=n;++j)
		{
			if(!check[j]&&minx>dis[j])
			{
				minx=dis[j];
				pos=j;
			}
		}
		check[pos]=1;
		for(int j=1;j<=n;++j)
		{
			if(!check[j]&&dis[j]>dis[pos]+mp[pos][j])
			{
				dis[j]=dis[pos]+mp[pos][j];
			}
		}
	}
	return dis[n];
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fill(mp[i],mp[i]+maxn,INF);
	}
	int a,b,c;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		mp[a][b]=mp[b][a]=c;
	}
	cout<<dijkstra(n)<<endl;
	return 0;
}
