/*题目描述
有栋个N层没有地下室的楼，这栋楼有一个奇怪的电梯，
这个电梯里面只有两个按钮，"UP" 或者 "DOWN"
当你在i层时，你只能到i+ki或者i-ki层
你想从A层去B层
请输出你最少要按多少次按钮

输入
输入多组样例
第一行包含三个整数N，A，B（1 <= N，A，B <= 200），如上所述，第二行包括N个整数k1，k2，...... kn。
单个0表示输入结束。
输出
入输出的每个情况一个整数，表示从A层去B层最少要按多少次按钮。

如果你不能到达B楼，则打印“-1”。

样例输入
5 1 5
3 3 1 2 5
0
样例输出
3*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,a,b;
int k[200];
struct node
{
	int vis;
	int step;
	int x;
};
int check(node e)
{
	if(e.x<a||e.x>b||!e.vis) return 0;
	else return 1;
}
int bfs(int a,int b)
{
	node next,cur;
	cur.vis=1;
	cur.step=1;
	cur.x=a;
	queue<node> q;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(cur.x==b)
		{
			return cur.step;
		}
		next.x=cur.x+k[cur.x];
		if(check(next))
		{
			next.step=cur.step+1;
			next.vis=1;
			q.push(next);
		}
		next.x=cur.x-k[cur.x];
		if(check(next))
		{
			next.step=cur.step+1;
			next.vis=1;
			q.push(next);
		}
	}
}

int main()
{
	
	
	cin>>n>>a>>b;
	for(int i;i<n;i++)
	{
		cin>>k[i];
	}
}
