/*
题目描述
    可可与人友好，经常喜欢设置一些有意思的游戏取人开心。今天她设置了一个迷宫让红红来走，她设计的迷宫是双向连通的，也就是说如果一个迷宫可以从A走到B，那么也一定可以从B走到A。为了提高难度，可可希望每两个顶点之间只有一条路可以通向对方(除非走了回头路)。可可现在把她的设计图给你，让你帮她判断她的设计是否符合她的设计思路。比如下面两个样例中，前两个是符合的，而最后一个由于从5->8的路径有两条不重复的路，因此不满足条件。




输入
输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，每一对数表示了一条通道连接的两个位置的编号。位置的编号至少为1，且不超过100000。每两组数据之间有一个空行。 
整个文件以两个-1结尾。 

输出
对于每组测试样例，输出仅包括一行。如果该迷宫符合可可的思路，那么输出"Yes"，否则输出"No"。 */
#include<iostream>
using namespace std;
#define maxn 100000
int pre[maxn];
int Find(int root)
{
	while(root!=pre[root])
	{
		root=pre[root];
	}
	return root;
}
int main()
{
	int a,b;
	int flag=1;
	while(cin>>a>>b)
	{
		flag=1;
		if(a==-1&&b==-1)
		{
			return 0;
		}
		for(int i=0;i<maxn;i++)
		{
			pre[i]=i;
		}
		pre[Find(a)]=Find(b);
		while(cin>>a>>b)
		{
			if(a==0&&b==0)
			{
				break;
			}
			a=Find(a);
			b=Find(b);
			if(a==b)
			{
				flag=0;
				pre[a]=b;
			}
			else 
			{
				pre[a]=b;
			}
		}
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}
