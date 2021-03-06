#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1010;
int pre[maxn];
bool visit[maxn];
int newpos[maxn];
int head[maxn];
struct Edge
{
	int to;
	int next;
}edge[maxn];
int cnt;
void addedge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}
int now;
void dfs(int x)
{
	newpos[now++]=x;
	for(int k=head[x];k!=-1;k=edge[k].next)
	{
		if(!visit[edge[k].to])
		{
			visit[edge[k].to]=true;
			pre[edge[k].to]=x;
			dfs(edge[k].to);
		}
	}
}
int n;
int mvc()
{
	bool s[maxn]={0};
	bool set[maxn]={0};
	int ans=0;
	for(int i=n-1;i>=1;i--)
	{
		int t=newpos[i];
		if(!s[t]&&!s[pre[t]])
		{
			set[pre[t]]=true;
			ans++;
			s[t]=true;
			s[pre[t]]=true;
		}
	}
	return ans;
}
void init()
{
	memset(head,-1,sizeof head);
	memset(visit,false,sizeof visit);
	now=0;
	cnt=0;
	visit[0]=true;
	pre[0]=0;
}
int main()
{
	while(cin>>n)
	{
		init();
		for(int i=0;i<n;i++)
		{
			int u,m;
			cin>>u>>m;
			while(m--)
			{
				int v;
				cin>>v;
				addedge(u,v);
			}
		}
		dfs(0);
		cout<<mvc()<<endl;
	}
	return 0;
}
