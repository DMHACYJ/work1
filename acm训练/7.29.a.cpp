/*
��Ŀ����
  ����n��������m������ʽ��ÿ������ʽ���� x[i] - x[j] <= a[k] (0 <= i j < n 0 <= k < m�� a[k]��֪)���� x[n-1] - x[0] �����ֵ��
����
��һ�� nm ��ʾ����n�������� m������ʽ

�������� m�� ������������abc ��ʾXa-Xb<=c;

���
���һ�н�� ��ʾ Xn-1-X0�����ֵ��*/
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
