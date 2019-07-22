#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000
int F[maxn];
int J[maxn];
double Y[maxn];
int m,n;
int check(double mid)
{
	for(int i=0;i<n;i++)
	{
		Y[i]=F[i]-mid*J[i];
	}
	sort(Y,Y+n);
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=Y[n-1-i];
	}
	return sum>=0;
}
int main()
{
	while(cin>>m>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>F[i]>>J[i];
		}
		double l=0,r=maxn,mid;
		for(int i=0;i<100;i++)
		{
			mid=(l+r)/2;
			if(check(mid))l=mid;
			else r=mid;
		}
		cout<<l*m<<endl;
	}
	return 0;
}
/*题目描述
红红准备了m斤肉肉准备和肉店兑换金钱以供自己上网码代码，现在有n家肉店，第i家肉店最多需要J[i]斤肉肉，如果全部交换红红可以获得F[i]美金，当然红红可以选择在某家肉店只交换一部分，红红问你他最多能获得多少美金。
输入
输入第一行包含两个正整数m，n分别表示红红初始拥有的肉肉的斤数和肉店数。

接下来n行，每行包括两个正整数分别表示第 i 家肉店的F[i] 和 J[i]，意思如题目所述，保证所有整数都小于1000.

输出
输出一个浮点数，表示红红能获得的最大美金数，保留小数点后三位。*/
