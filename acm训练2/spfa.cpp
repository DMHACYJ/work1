#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<map>
using namespace std;
const int maxn=1010;
map<string,int> mp;
int n;
struct Money
{
	int to,next;
	double cost;
}edge[maxn];
int head[maxn];
int cnt;
void init()
{
	memset(head,-1,sizeof head);
	cnt=0;
}
void addedge(int u,double cost,int v)
{
	edge[cnt].to=v;
	edge[cnt].cost=cost;
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}
bool vis[maxn];
int num[maxn];
//int pre[maxn];
double dist[maxn];
bool spfa(int b)
{
	memset(vis,false,sizeof vis);
	memset(num,0,sizeof num);
//	memset(pre,-1,sizeof pre);
	memset(dist,0,sizeof dist);
	int flag=0;
	vis[b]=true;
	dist[b]=1;
	num[b]=1;
	queue<int> que;
	while(!que.empty()) que.pop();
	que.push(b);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u]=false;
		int i;
		for(i=head[u];~i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dist[v]<dist[u]*edge[i].cost)
			{
				flag=1;
				dist[v]=dist[u]*edge[i].cost;
//				pre[v]=u;
				if(!vis[v])
				{
					vis[v]=true;
					que.push(v);
					if(++num[v]>n&&dist[v]>1) return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int m;
	int ans=1;
	while(cin>>n&&n)
	{
		init();
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			mp[s]=i;
		}
		cin>>m;
		while(m--)
		{
			string u,v;
			double cost;
			cin>>u>>cost>>v;
			addedge(mp[u],cost,mp[v]);
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(spfa(i))
			{
				flag=1;
			}
		}
		if(flag)
		{
			cout<<"Case "<<ans++<<": Yes"<<endl;
		}
		else cout<<"Case "<<ans++<<": No"<<endl;
	}
	return 0;
}
