/*
��Ŀ����
����������֯��һ����ţ���㷨������ÿͷ��ţ�����Լ��Ĵ���������һ��������ѡ�����Լ��Ĵ������Ͼ��Ѿ���ȫ�����˳������������Ǹ���һЩ��ϵ��ʾ��ͷţ֮��˭��ǿһ�㣬������Щ��ϵ����Ҫȷ�����е�ţ������Щţ��λ����ȷ���ġ������ȷ��λ�ε���ţ��Ŀ��
����
�����һ����������nm�ֱ��ʾ n ������ţ����Ŀ��m������ǹ�ϵ����Ŀ��

��������m��������������ab�������a��bҪ����������������ҲӦ����b��ǰ�档

���뷶Χ ����int��������

���
���һ�д������ȷ��λ�ε�ţ����Ŀ��*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
int mp[maxn][maxn];
int in[maxn];
int out[maxn];
int main()
{
	int m,n;
	cin>>n>>m;
	int cnt=0;
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		mp[a][b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[j][i])
			{
				for(int k=1;k<=n;k++)
				{
					mp[j][k]=mp[j][k]|mp[i][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j])
			{
				out[i]++;
				in[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(out[i]+out[i]==n-1)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
