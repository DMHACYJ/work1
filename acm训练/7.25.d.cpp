#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node
{
	int x;
	int y;
	int cnt;
	node(int x=0,int y=0,int cnt=0)
	{
		this->x=x;
		this->y=y;
		this->cnt=cnt;
	}
};
int mp[5][5];
int vis[5][5];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int step[5][5];
node pre[5][5];
int check(node n)
{
	if(n.x<0||n.x>4||n.y<0||n.y>4) return 0;
	if(mp[n.x][n.y]==1||vis[n.x][n.y]==1) return 0;
	else return 1;
}
void bfs()
{
	memset(vis,0,sizeof(vis)) ;
	memset(step,-1,sizeof(step));
	node now;
	queue<node> q;
	now.x=0;
	now.y=0;
	now.cnt=0;
	q.push(now);
	step[now.x][now.y]=0;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		vis[now.x][now.y]=1;
		step[now.x][now.y]=now.cnt;
		if(now.x==4&&now.y==4) return;
		for(int i=0;i<4;i++)
		{
			node next;
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(check(next))
			{
				next.cnt=now.cnt+1;
				q.push(next);
				pre[next.x][next.y]=now;
			}
		}
	}
	return;
}
void printpath(node n)
{
	stack<node> s;
	for(;;)
	{
		s.push(n);
		if(step[n.x][n.y]==0)
		{
			break;
		}
		n=pre[n.x][n.y];
	}
	while(!s.empty())
	{
		cout<<"("<<(s.top().x)<<", "<<(s.top().y)<<")"<<endl;
		s.pop();
	}
}
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>mp[i][j];
		}
	}
	bfs();
	node n(4,4,step[4][4]);
	printpath(n);
	return 0;
}
