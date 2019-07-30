/*
题目描述
  给定n个变量和m个不等式，每个不等式形如 x[i] - x[j] <= a[k] (0 <= i j < n 0 <= k < m， a[k]已知)，求 x[n-1] - x[0] 的最大值。
输入
第一行 nm 表示的是n个变量和 m个不等式

接下来的 m行 会输入三个数abc 表示Xa-Xb<=c;

输出
输出一行结果 表示 Xn-1-X0的最大值。*/
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1005;
const int maxm=10005;
const int INF=0x3f3f3f3f;
struct Edge
{
	int to,co,next;
	Edge(int to=0,int co=0,int next=0)
	{
		this->to=to;
		this->co=co;
		this->next=next;
	}
}edge[maxm];
int n,m;
int head[maxn];
bool check[maxn];
int dis[maxn];
void spfa(int s,int end)
{
	fill(dis,dis+maxn,INF);
	memset(check,false,sizeof check);
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		check[u]=false;
		for(int i=head[u];~i;i=edge[i].next)
		{
			Edge e=edge[i];
			if(dis[e.to]>dis[u]+e.co)
			{
				dis[e.to]=dis[u]+e.co;
				if(!check[e.to])
				{
					q.push(e.to);
					check[e.to]=true;
				}
			}
		}
	}
	cout<<dis[end]<<endl;
}
int main()
{
	memset(head,-1,sizeof head);
	cin>>n>>m;
	int tot=0;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edge[tot]=Edge(b,c,head[a]);
		head[a]=tot++;
	}
	spfa(n-1,0);
	return 0;
} 
