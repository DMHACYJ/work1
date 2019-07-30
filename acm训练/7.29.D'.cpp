#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=30;
const int maxm=80;
struct edge
{
	int u,v,w,next;
	friend bool operator < (edge a,edge b)
	{
		return a.w>b.w;
	}
}e[maxm];
int vis[maxn];
int head[maxn];
int prime(int b,int n)
{
	vis[b]=1;
	int ans=0;
	int count=1;
	priority_queue<edge>q;
	for(int i=head[b];i!=-1;i=e[i].next)
	{
		q.push(e[i]);
	}
	while(!q.empty())
	{
		edge now=q.top();
		q.pop();
		if(!vis[now.v])
		{
			ans+=now.w;
			vis[now.v]=1;
			if(count==n) break;
			for(int i=head[now.v];i!=-1;i=e[i].next)
			{
				q.push(e[i]);
			}
		}
	}
	return ans;
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		int cnt=0;
		memset(head,-1,sizeof head);
		memset(vis,0,sizeof vis);
		for(int i=1;i<n;i++)
		{
			char s[2];
			int temp;
			scanf("%s %d",s,&temp);
			for(int j=1;j<=temp;j++)
			{
				int a;
				char ss[2];
				scanf("%s %d",s,&a);
				e[++cnt].u=i;
				e[cnt].v=s[0]-'A'+1;
				e[cnt].w=a;
				e[cnt].next=head[i];
				head[i]=cnt;
				e[++cnt].u=s[0]-'A'+1;
				e[cnt].v=i;
				e[cnt].w=a;
				e[cnt].next=head[s[0]-'A'+1];
				head[s[0]-'A'+1]=cnt;
			}
		}
		cout<<prime(1,n)<<endl;
	}
	return 0;
}
