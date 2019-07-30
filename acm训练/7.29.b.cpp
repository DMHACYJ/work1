/*
��Ŀ����
���ƿɰ�������֣���ʵƢ��Ҳ��С�أ���һ�������ǳԲݵ�ʱ�����ֵ����쾡�¡���Ⱥţ��1~n���α�Ų�������վ���Բݵ��������м���Щţ�����໥��ϲ����ţ����Ҳ��Ϊ�ѣ�ֻ����������֮��ľ��벻С��ĳ��ֵ����ͷţ�Ų����໥Ӱ�죬�е�ţ֮���໥��ϲ����������˴�����Χ�����ƽ���θ�ھ�û�ˣ�����֮��ľ�����벻����ĳ��ֵ����������������ţ��Ҫ�������£�ţ���������������һͷţ�����һͷţ�����Ŀ��ܾ����Ƕ��١�
����
�����������������н⡣

��һ������N��ML��MD�������ֱ�������ţ����Ŀ������ϲ���Ķ��������಻ϲ���Ķ�������2<=NMLMD<=200��

��������ML������abc�����������aͷţ�͵�bͷţ֮����벻����c��(1<=abc<=1000)

��������MD������abc�����������aͷţ�͵�bͷţ֮����벻С��c;  (1<=abc<=1000)


���
���һ������ʾ���ܵĽ��.
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
