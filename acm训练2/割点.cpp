#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=10007;
const int maxm=100007;
struct Edge
{
	int u,v;
	int next;
}edge[maxm];
int dfn[maxn];
int low[maxn];
int head[maxn];
int vis[maxn];
int cnt,total;
stack<int> st;
void init()
{
	while(!st.empty()) st.pop();
	memset(head,-1,sizeof head);
	cnt=0;
	total=0;
}
void addedge(int u,int v)
{
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++total;
	st.push(u);
	int k=0;
	for(int i=head[u];~i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!dfn[v])
		{
			k++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if((u!=fa&&dfn[u]<=low[v])||(u==fa&&k>1))
			{
				vis[u]=1;
			}
		}
		else if(fa!=v) 
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	init();
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i,i);
		} 
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			cout<<i<<endl;
		}
	}
	return 0;
} 
