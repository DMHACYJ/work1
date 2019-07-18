#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,k;
int check[100000];
int cur;
struct node
{
	int x,step;
};
int bfs(int n,int k)
{
	memset(check,0,sizeof(check));
	queue<node> q;
	node cur,next;
	
	cur.x=n;
	cur.step=0;
	check[cur.x]=1;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		check[cur.x]=1;
		q.pop();
		if(cur.x==k)
		{
			return cur.step;
		}
		next.step=cur.step+1;
		next.x=cur.x-1;
		if(next.x>0&&check[next.x]==0)
		{
			q.push(next);
			check[cur.x]=1;
		}
		next.x=cur.x+1;
		if(next.x<=100000&&check[next.x]==0)
		{
			q.push(next);
			check[cur.x]=1;
		}
		next.x=cur.x*2;
		if(next.x<=100000&&check[next.x]==0)
		{
			q.push(next);
			check[cur.x]=1;
		}
	}
	
}
int main()
{
	while(cin>>n>>k)
	{
		
		int step=bfs(n,k);
		step*=10;
		cout<<step/60<<":"<<step%60<<endl;
	}
}
