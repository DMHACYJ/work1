/*
��Ŀ����
���⣬��֪һ�����У�����Ҫ�����������ֲ�����

1.��ĳ����ÿһ����������x

2.���ĳһ������ֵ

���������ʽ
�����ʽ��
��һ�а�����������N��M���ֱ��ʾ���������ֵĸ����Ͳ������ܸ�����

�ڶ��а���N���ÿո�ָ������������е�i�����ֱ�ʾ���е�i��ĳ�ʼֵ��

������M��ÿ�а���2��4����������ʾһ���������������£�

����1�� ��ʽ��1 x y k ���壺������[x,y]��ÿ��������k

����2�� ��ʽ��2 x ���壺�����x������ֵ

�����ʽ��
���������������������Ϊ���в���2�Ľ����*/
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
