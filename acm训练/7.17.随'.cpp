#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
const int maxn=10+8;
int map[maxn][maxn];
int vis[maxn][maxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct node
{
	int x;
	int y;
	node(int x=0,int y=0)
	{
		this->x=x;
		this->y=y;
	}
};
node far[maxn][maxn];
int check(node t)
{
	if(t.x<0||t.x>4||t.y<0||t.y>4) return 0;
	if(map[t.x][t.y]==1||vis[t.x][t.y]==1) return 0;
	return 1;
}
void bfs()
{
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node now;
	now.x=0;
	now.y=0;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		vis[now.x][now.y]=1;
		for(int i=0;i<4;i++)
		{
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(check(next))
			{
				q.push(next);
				far[next.x][next.y]=now;
			}
		}
	}
}
void printf_path(node u)
{
	stack<node> s;
	for(;;)
	{
		s.push(u);
		if(u.x==0&&u.y==0) break;
		u=far[u.x][u.y];
	}
	while(!s.empty())
	{
		printf("(%d, %d)\n",(s.top()).x,(s.top()).y);
		s.pop();
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	bfs();
	node ans(4,4);
	printf_path(ans);
	return 0;
}
