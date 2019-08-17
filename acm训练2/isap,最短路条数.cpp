#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=407;
const int maxm=20211;
const int inf=0x3f3f3f3f;
int cnt=0;
int head[maxn];
int dep[maxn];
int gap[maxn];
int s,t;
int n;
struct Node
{
	int v;
	int next;
	int val;
}node[maxm];
void add(int u,int v,int val)
{
	node[++cnt].v=v;
	node[cnt].val=val;
	node[cnt].next=head[u];
	head[u]=cnt;
}
void bfs()
{
	memset(dep,-1,sizeof dep);
	memset(gap,0,sizeof(gap));
	dep[t]=0;
	gap[0]=1;
	queue<int> q;
	q.push(t);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=node[i].next)
		{
			int v=node[i].v;
			if(dep[v]!=-1) continue;
			q.push(v);
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}
	return;
}
int maxflow=0;
int dfs(int u,int flow)
{
	if(u==t)
	{
		maxflow+=flow;
		return flow;
	}
	int used=0;
	for(int i=head[u];i;i=node[i].next)
	{
		int d=node[i].v;
		if(node[i].val&&dep[d]+1==dep[u])
		{
			int mi=dfs(d,min(node[i].val,flow-used));
			if(mi)
			{
				node[i].val+=mi;
				node[i^1].val+=mi;
				used+=mi;
			}
			if(used==flow) return used;
		}
	}
	--gap[dep[u]];
	if(gap[dep[u]]==0) dep[s]=n+1;
	dep[u]++;
	gap[dep[u]]++;
	return used;
}
int isap()
{
	bfs();
	while(dep[s]<n) dfs(s,inf);
	return maxflow;
}
int main()
{
	int m;
	cin>>n>>m;
	init();
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w,edge,cnt,head);
		add(v,u,w,uedge,ucnt,uhead);
	}
	int b,e;
	cin>>b>>e;
	s=b,t=e;
	cout<<isap()<<endl;
	return 0;
}
