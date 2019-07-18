/*��Ŀ����
�ж���N��û�е����ҵ�¥���ⶰ¥��һ����ֵĵ��ݣ�
�����������ֻ��������ť��"UP" ���� "DOWN"
������i��ʱ����ֻ�ܵ�i+ki����i-ki��
�����A��ȥB��
�����������Ҫ�����ٴΰ�ť

����
�����������
��һ�а�����������N��A��B��1 <= N��A��B <= 200���������������ڶ��а���N������k1��k2��...... kn��
����0��ʾ���������
���
�������ÿ�����һ����������ʾ��A��ȥB������Ҫ�����ٴΰ�ť��

����㲻�ܵ���B¥�����ӡ��-1����

��������
5 1 5
3 3 1 2 5
0
�������
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
