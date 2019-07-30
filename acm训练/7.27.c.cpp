/*
题目描述
Michael喜欢滑雪这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道在一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子 

1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

输入
输入的第一行表示区域的行数R和列数C(1 <= RC <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。*/
#include<iostream>
#include<cstring>
using namespace std;
int num[105][105];
int len[105][105];
int r,c;
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y)
{
	if(len[x][y]!=0)
	{
		return len[x][y];
	}
	int tx,ty,ms=0,s;
	for(int k=0;k<4;k++)
	{
		tx=dis[k][0]+x;
		ty=dis[k][1]+y;
		if(tx<0||tx>c-1||ty<0||ty>r-1)
		{
			continue;
		}
		if(num[tx][ty]<num[x][y])
		{
			s=dfs(tx,ty);
			ms=max(ms,s);
		}
	}
	len[x][y]=ms+1;
	return len[x][y];
}
int main()
{
	while(cin>>r>>c)
	{
		memset(len,0,sizeof(len));
		memset(num,0,sizeof(num));
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>num[i][j];
			}
		}
		int ms=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				ms=max(ms,dfs(i,j));
			}
		}
		cout<<ms<<endl;
	}
	return 0;
}
