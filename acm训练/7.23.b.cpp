/*
题目描述
可可这个暑假因为天天清空购物车的问题，小金库日益变薄，于是她决定去赚点钱钱。

这天她来到街上，询问店里招不招暑假工，可是她希望能够离学校近一点，钱多一点，事少一点的工作。

街上的店给出暑假工的薪资报价，可可希望能在她比较中意的范围内找到工资最高的店，但是呢，因为金融市场变化比较大的问题，有些店会经常修改工资，但是一家店修改了，会导致周围几家也修改，所以这时候她决定通过区间查询的方式查看该区域的最大工资。

输入
第一行包括N 和 M， N表示店铺总数， M 表示执行的操作数 （ 1<= N M <= 500000)

第二行包括N个数字，表示编号为1 到N的店铺给的初始价格

随后M行，每一行有三到四个数字，?ａ，ｂ，ｃ（ｄ）

ａ表示操作种类，ａ为１的时候表示将ｂ到ｃ的店铺的价格加上ｄ（１０＞｜ｂ?－?ｃ｜＞＝０）?ｂ＜ｃ

ａ?为２的时候表示查询ｂ到ｃ范围内店铺的最高价格

输出
对于每一个ａ为２的查询，输出一行查询区间内的最大值*/
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 500000
int num[maxn];
struct tree
{
	int l;
	int r;
	int price;
}dp[maxn];
void build(int k,int l,int r)
{
	dp[k].l=l;
	dp[k].r=r;
	if(l==r)
	{
		dp[k].price=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	dp[k].price=max(dp[k<<1].price,dp[k<<1|1].price);
}
int get_max(int k,int l,int r)
{
	int res=0;
	if(l<=dp[k].l&&r>=dp[k].r)
	{
		return dp[k].price;
	}
	int mid=(dp[k].r+dp[k].l)>>1;
	if(l<=mid) res=max(res,get_max(k<<1,l,r));
	if(r>mid) res=max(res,get_max(k<<1|1,l,r));
	return res;
}
void update(int k,int x,int y)
{
	if(dp[k].l==dp[k].r)
	{
		dp[k].price=y;
		return;
	}
	int mid=(dp[k].l+dp[k].r)>>1;
	if(x<=mid) update(k<<1,x,y);
	else update(k<<1|1,x,y);
	dp[k].price=max(dp[k<<1].price,dp[k<<1|1].price);
}
int main()
{
	int n,m;
	int a,b,c,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	build(1,1,n);
	while(m--)
	{
		cin>>a;
		if(a==2)
		{
			cin>>b>>c;
			cout<<get_max(1,b,c)<<endl;
		}
		else if(a==1)
		{
			cin>>b>>c>>d;
			for(int i=b;i<=c;i++)
			{
				num[i]+=d;
				update(1,i,num[i]);
			}
		}
	}
	return 0;
} 
