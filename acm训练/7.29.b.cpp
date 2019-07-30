/*
题目描述
看似可爱的哞哞怪，其实脾气也不小呢，这一点在他们吃草的时候体现的淋漓尽致。这群牛从1~n依次编号并且依次站立吃草但是他们中间有些牛就是相互不喜欢，牛主人也很为难，只有满足他们之间的距离不小于某个值这两头牛才不会相互影响，有的牛之间相互很喜欢如果见到彼此在周围，估计今天胃口就没了，他们之间的距离必须不大于某个值。所以在满足所有牛的要求的情况下，牛主人想让你算算第一头牛到最后一头牛的最大的可能距离是多少。
输入
所有输入样例满足有解。

第一行输入N，ML，MD三个数分别代表的是牛的数目，互相喜欢的对数，互相不喜欢的对数。（2<=NMLMD<=200）

接下来的ML行输入abc三个数代表第a头牛和第b头牛之间距离不超过c；(1<=abc<=1000)

接下来的MD行输入abc三个数代表第a头牛和第b头牛之间距离不小于c;  (1<=abc<=1000)


输出
输出一个数表示可能的结果.
*/
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
int n;
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
	int ml,md;
	cin>>n>>ml>>md;
	int tot=0;
	while(ml--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edge[tot]=Edge(b,c,head[a]);
		head[a]=tot++;
	}
	while(md--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		edge[tot]=Edge(a,-c,head[b]);
		head[b]=tot++;
	}
	spfa(1,n);
	return 0;
} 
