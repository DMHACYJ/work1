/*
题目描述
如题，已知一个数列，你需要进行下面两种操作：

1.将某区间每一个数数加上x

2.求出某一个数的值

输入输出格式
输入格式：
第一行包含两个整数N、M，分别表示该数列数字的个数和操作的总个数。

第二行包含N个用空格分隔的整数，其中第i个数字表示数列第i项的初始值。

接下来M行每行包含2或4个整数，表示一个操作，具体如下：

操作1： 格式：1 x y k 含义：将区间[x,y]内每个数加上k

操作2： 格式：2 x 含义：输出第x个数的值

输出格式：
输出包含若干行整数，即为所有操作2的结果。*/
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100
int num[maxn];
int tree[maxn];
int n,m;
int lowbit(int x)
{
	return x&(-x);
}
void update(int i,int x)
{
	for(int j=i;j<=n;j+=lowbit(j))
	{
		tree[j]+=x;
	}
}
int getsum(int i)
{
	int res=0;
	for(int j=i;j>=1;j-=lowbit(j))
	{
		res+=tree[j];
	}
	return res;
}
int main()
{
	cin>>n>>m;
	memset(num,0,sizeof(num));
	for(int i=1;i<=m;i++)
	{
		cin>>num[i];
		update(i,num[i]-num[i-1]);
	}
	int c,x,y,k;
	while(m--)
	{
		cin>>c;
		if(c==1)
		{
			cin>>x>>y>>k;
			update(x,k);
			update(y+1,-k);
		}
		else
		{
			cin>>x;
			cout<<getsum(x)<<endl;
		}
	}
	return 0;
} 
