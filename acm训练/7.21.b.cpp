/*
��Ŀ����
�����������һ�ݼ�ְ�������˲�һ���ַ�����ĳ�����ʵĳ��ִ�����


������̫��ʱ�������æ��������������������һ�����ְ�����

����
��һ������һ�� T ������������Ŀ��


ÿ�����ݵ�һ��������Ҫ���ҵĵ��ʡ�

�ڶ�����������ϳ����ַ���������С��1000010����

���
ÿ���������һ�� n ������Ҫ������ʳ��ֵĴ�����*/
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int nit[1000010];
void _next(string p)
{
	int k=-1;
	int i=0;
	nit[0]=-1;
	while(i<p.size()-1)
	{
		if(k==-1||p[i]==p[k])
		{
			k++;
			i++;
//			if(p[i]!=p[k])
//			{
				nit[i]=k;
//			}
//			else next[i]=next[k];
		}
		else
		{
			k=nit[k];
		} 
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a,b;
		cin>>a>>b;

		_next(b);
		
		int now=0;
		int num=0;
		int i=0;
		while(i<b.length())
		{
			
			if(a[now]==b[i])
			{
				now++;
				i++;
			}
			else if(now>=0)
			{
				now=nit[now];
			}
			else
			{
				++i;
				now=0;
			}
			if(now==a.length())
			{
				num++;
				now=nit[now];
			}	
		}
		cout<<num<<endl;
	}
	return 0;
}
