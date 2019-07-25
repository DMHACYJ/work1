/*
��Ŀ����
�ɿ���������Ϊ������չ��ﳵ�����⣬С�������䱡������������ȥ׬��ǮǮ��

�������������ϣ�ѯ�ʵ����в�����ٹ���������ϣ���ܹ���ѧУ��һ�㣬Ǯ��һ�㣬����һ��Ĺ�����

���ϵĵ������ٹ���н�ʱ��ۣ��ɿ�ϣ���������Ƚ�����ķ�Χ���ҵ�������ߵĵ꣬�����أ���Ϊ�����г��仯�Ƚϴ�����⣬��Щ��ᾭ���޸Ĺ��ʣ�����һ�ҵ��޸��ˣ��ᵼ����Χ����Ҳ�޸ģ�������ʱ��������ͨ�������ѯ�ķ�ʽ�鿴�����������ʡ�

����
��һ�а���N �� M�� N��ʾ���������� M ��ʾִ�еĲ����� �� 1<= N M <= 500000)

�ڶ��а���N�����֣���ʾ���Ϊ1 ��N�ĵ��̸��ĳ�ʼ�۸�

���M�У�ÿһ���������ĸ����֣�?�ᣬ�⣬�㣨�䣩

���ʾ�������࣬��Ϊ����ʱ���ʾ���⵽��ĵ��̵ļ۸���ϣ䣨����������?��?�����������?�⣼��

��?Ϊ����ʱ���ʾ��ѯ�⵽�㷶Χ�ڵ��̵���߼۸�

���
����ÿһ����Ϊ���Ĳ�ѯ�����һ�в�ѯ�����ڵ����ֵ*/
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
