/*
��Ŀ����
Сѧ�������N�������ų�һ�ţ����������α��Ϊ123....N.ÿ�θ���2������a b(a <= b)��Ƥ�ĺ����ӵ�кܶ��ֲ�ͬ��ɫ������������������a��ʼ������b���θ�ÿ������Ϳһ����ɫ������N���Ժ����Ѿ������˵�I�������Ѿ�Ϳ��������ɫ�ˣ����ܰ������ÿ������Ϳ��������ɫ��

����
ÿ������ʵ����һ��Ϊһ������N(N <= 100000).��������N�У�ÿ�а���2������a b(1 <= a <= b <= N)�� 
��N = 0�����������

���
ÿ������ʵ�����һ�У�����N����������I���������I�������ܹ���Ϳɫ�Ĵ�����*/
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
