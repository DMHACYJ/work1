#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1010;
struct Edge
{
	int to,cost,next;
}edge[maxn];
int head[maxn];
int cnt;
void init()
{
	memset(head,-1,sizeof head);
	cnt=0;
}
void addedge(int u,int v)
{
	edge[cnt].to=v;
//	edge[cnt].cost=w
	edge[cnt].next=head[u]; 
	head[u]=cnt++;
}
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	init();
	while(m--)
	{
		cin>>u>>v;
		addedge(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];~j;j=edge[j].next)
		{
			cout<<i<<" "<<(edge[j].to)<<endl;
		}
	}
	return 0;
} 
