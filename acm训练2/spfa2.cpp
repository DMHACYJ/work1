#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1010;
const int maxm=10010;
const int inf=0x3f3f3f3f;
struct Edge
{
	int to,next,cost;
}edge[maxm];
int head[maxn];
int cnt;
void addedge(int u,int v,int cost)
{
	edge[cnt].to=v;
	edge[cnt].cost=cost;
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}
bool vis[maxn];
int num[maxn];
//int pre[maxn];
int dist[maxn];
void init()
{
	memset(head,-1,sizeof head);
	cnt=0;
	memset(vis,false,sizeof vis);
	memset(num,0,sizeof num);
	fill(dist,dist+maxn,inf);
}
int n;
int spfa(int b)
{
	vis[b]=true;
	dist[b]=0;
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
			if(dist[v]>dist[u]+edge[i].cost)
			{
				dist[v]=dist[u]+edge[i].cost;
				if(!vis[v])
				{
					vis[v]=true;
					que.push(v);
					if(++num[v]>n) return -1;
				}
			}
		}
	}
	return dist[n]==inf?-2:dist[n];
}
int main()
{
	int ml,md;
	init();
	cin>>n>>ml>>md;
	int a,b,d;
	while(ml--)
	{
		cin>>a>>b>>d;
		addedge(a,b,d);
	}
	while(md--)
	{
		cin>>a>>b>>d;
		addedge(b,a,-d);
	}
	cout<<spfa(1)<<endl;
	return 0;
}
