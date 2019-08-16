#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=505;
const int maxm=2525;
const int inf=0x3f3f3f3f;
struct Edge
{
	int to,next,cost;
}edge[maxm];
int head[maxn];
int cnt;
void init()
{
	memset(head,-1,sizeof head);
	cnt=0;
}
void addedge(int u,int v,int cost)
{
	edge[cnt].to=v;
	edge[cnt].cost=cost;
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}
bool vis[maxn];
//int num[maxn];
//int pre[maxn];
double dist[maxn];
bool spfa(int b)
{
	memset(vis,false,sizeof vis);
//	memset(num,0,sizeof num);
//	memset(pre,-1,sizeof pre);
	fill(dist,dist+maxn,inf);
	int flag=0;
	vis[b]=true;
	dist[b]=1;
//	num[b]=1;
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
			if(dist[v]>dist[u]+edge[i].cost)
			{
				flag=1;
				dist[v]=dist[u]+edge[i].cost;
//				pre[v]=u;
				if(!vis[v])
				{
					vis[v]=true;
					que.push(v);
					if(v==b&&dist[v]<0) return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int f;
	cin>>f;
	while(f--)
	{
		init();
		int n,v,w;
		cin>>n>>v>>w;
		while(v--)
		{
			int s,e,cost;
			cin>>s>>e>>cost;
			addedge(s,e,cost);
			addedge(e,s,cost);
		}
		while(w--)
		{
			int s,e,cost;
			cin>>s>>e>>cost;
			addedge(s,e,-cost);
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
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
