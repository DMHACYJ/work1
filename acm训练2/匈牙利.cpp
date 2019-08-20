#include<iostream>
#include<cstring>
using namespace std;
const int maxn=507;
const int maxm=1010;
int pre[maxn];
bool visit[maxn];
int newpos[maxn];
int head[maxn];
struct Edge
{
	int to;
	int next;
}edge[maxm];
int cnt;
void addedge(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}

bool dfs(int x)
{
	for(int k=head[x];k!=-1;k=edge[k].next)
	{
		if(!visit[edge[k].to])
		{
			visit[edge[k].to]=true;
			if(pre[edge[k].to]==-1||dfs(pre[edge[k].to]))
			{
				pre[edge[k].to]=x;
				return true;
			}
		}
	}
	return false;
}
int n;
int hungary()
{
	int ans=0;
	memset(pre,-1,sizeof pre);
	for(int i=1;i<=n;i++)
	{
		memset(visit,false,sizeof visit);
		if(dfs(i)) ans++;
	}
	return ans;
}
void init()
{
	memset(head,-1,sizeof head);
	cnt=0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		init();
		int m;
		cin>>n>>m;
		for(int u=1;u<=n;u++)
		{
			int p;
			cin>>p;
			while(p--)
			{
				int v;
				cin>>v;
				addedge(u,v);
			}
		}
		if(hungary()==n)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl; 
	}
	return 0;
}
