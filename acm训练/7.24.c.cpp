/*
题目描述
小学生红红有N个气球排成一排，从左到右依次编号为123....N.每次给定2个整数a b(a <= b)调皮的红红想拥有很多种不同颜色的气球，于是他从气球a开始到气球b依次给每个气球涂一次颜色。但是N次以后红红已经忘记了第I个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？

输入
每个测试实例第一行为一个整数N(N <= 100000).接下来的N行，每行包括2个整数a b(1 <= a <= b <= N)。 
当N = 0，输入结束。

输出
每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define maxn 100020
int n;
int a[maxn];
int lowbit(int j)
{
	return j&(-j);
}
void updata(int i,int temp)
{
	for(int j=i;j<=n;j+=lowbit(j))
	{
		a[j]+=temp;
	}
}
int getsum(int i)
{
	int res=0;
	for(int j=i;j>0;j-=lowbit(j))
	{
		res+=a[j];
	}
	return res;
}
int main()
{
	int x,y;
	while(cin>>n&&n)
	{
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++)
		{
			cin>>x>>y;
			updata(x,1);
			updata(y+1,-1);
		}
		for(int i=1;i<=n;i++)
		{
			cout<<getsum(i)<<" ";
		}
		cout<<endl;
	}
	return 0;
}
