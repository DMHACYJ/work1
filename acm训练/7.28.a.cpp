#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2525;
int mp[maxn][maxn];
int check[maxn];
int dis[maxn];
void dijkstra(int t,int ts)
{
	memset(check,0,sizeof(check));
	fill(dis,dis+maxn,INF);
	for(int i=1;i<=t;++i)
	{
		dis[i]=mp[ts][i];
	}
	check[ts]=1;
	dis[ts]=0;
	int minx,pos;
	for(int i=1;i<t;++i)
	{
		minx=INF;
		for(int j=1;j<=t;++j)
		{
			if(!check[j]&&minx>dis[j])
			{
				minx=dis[j];
				pos=j;
			}
		}
		check[pos]=1;
		for(int j=1;j<=t;++j)
		{
			if(!check[j]&&dis[j]>dis[pos]+mp[pos][j])
			{
				dis[j]=dis[pos]+mp[pos][j];
			}
		}
	}
}
int main()
{
	int t,m,ts,te;
	cin>>t>>m>>ts>>te;
	int s,e,c;
	for(int i=1;i<=t;i++)
	{
		fill(mp[i],mp[i]+maxn,INF);
	}
	for(int i=0;i<m;i++)
	{
		cin>>s>>e>>c;
		if(mp[s][e]>c)
		{
			mp[s][e]=mp[e][s]=c;
		}
	}
	dijkstra(t,ts);
	cout<<dis[te]<<endl;
	return 0;
} 
