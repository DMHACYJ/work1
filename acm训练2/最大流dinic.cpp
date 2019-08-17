#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=407;
const int maxm=20211;
const int inf=0x3f3f3f3f;
int cnt=1;
int head[maxn];
int dep[maxn];
int cur[maxn];
int s,t;
vector<int> F[105];
vector<int> D[105];
struct Edge
{
	int v;
	int next;
	int val;
}edge[maxm];
void init()
{
	cnt=-1;
	memset(head,-1,sizeof(head));
	for(int i=0;i<105;i++)
	{
		F[i].clear();
		D[i].clear();
	}
}
void add(int u,int v,int val)
{
	edge[++cnt].v=v;
	edge[cnt].val=val;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int bfs()
{
	memset(dep,0,sizeof dep);
	queue<int> q;
	while(!q.empty()) q.pop();
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			int val=edge[i].val;
			if(val>0&&dep[v]==0)
			{
				q.push(v);
				dep[v]=dep[u]+1;
			}
		}
	}
	if(dep[t]==0)
	{
		return 0;
	}
	return 1;
}
int dfs(int u,int flow)
{
	if(u==t)
	{
		return flow;
	}
	for(int &i=cur[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].v;
		int val=edge[i].val;
		if((dep[v]==dep[u]+1)&&val!=0)
		{
			int mi=dfs(v,min(val,flow));
			if(mi>0)
			{
				edge[i].val-=mi;
				edge[i^1].val+=mi;
				return mi;
			}
		}
	}
	return 0;
}
int dinic()
{
	int ans=0;
	while(bfs())
	{
		for(int i=s;i<=t;i++)
		{
			cur[i]=head[i];
		}
		while(int d=dfs(s,inf))
		{
			ans+=d;
		}
	}
	return ans;
}
int main()
{
	int n,f,d;
	cin>>n>>f>>d;
	init();
	for(int i=1;i<=f;i++) 
	{
		add(0,i,1);
		add(i,0,1);
	}
	for(int i=1;i<=d;i++) 
	{
		add(f+2*n+i,f+2*n+d+1,1);
		add(f+2*n+d+1,f+2*n+i,1);
	}
	for(int i=1;i<=n;i++)
	{
		int nf,nd,tmp;
		cin>>nf>>nd;
		while(nf--)
		{
			cin>>tmp;
			F[i].push_back(tmp);
		}
		while(nd--)
		{
			cin>>tmp;
			D[i].push_back(tmp);
		}
	}
	for(int i=1;i<=n;i++)
	{
		add(f+i,f+n+i,1);
		add(f+n+i,f+i,1);
		for(int j=0;j<F[i].size();j++)
		{
			add(F[i][j],f+i,1);
			add(f+i,F[i][j],1);
		}
		for(int j=0;j<F[i].size();j++)
		{
			add(f+n+i,f+2*n+D[i][j],1);
			add(f+2*n+D[i][j],f+n+i,1);
		}
	}
	s=0,t=f+2*n+d+1;
	cout<<dinic()<<endl;
	return 0;
}
