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
void tarjan(int u)
{
	dfn[u]=low[u]=++total;
	st.push(u);
	for(int i=head[u];~i;i=edge[i].next)
	{
		int v=edge[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m&&n&&m)
	{
		init();
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			addedge(a,b);
		}
		tarjan(1);
		if(st.size()==n)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}
