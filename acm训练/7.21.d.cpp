/*
��Ŀ����
������N�����ȱȽ϶̵�ţ�⴮��������һ�����ȱȽϳ���ţ�⴮��ţ�⴮�������ַ���ɣ�������֪�������ÿһ��ţ�⴮���Լ���ţ�⴮�г��ֵĴ�����

����
����������ݡ�

����һ������N���������N��ţ�⴮��1 <= N <= 10��

������N��Ϊ�����ţ�⴮�е��ַ����ַ������Ȳ�����10��

��N+1�У�������ţ�⴮�е��ַ����ַ������Ȳ�����100��

���
���һ�����ִ��������N��ţ�⴮�ڿ�����ţ�⴮�г��ֵĴ�����*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int nit[10000];
void getnext(string s)
{
	int i=0;
	int	k=-1;
	nit[0]=-1;
	while(i<s.size()-1) 
	{
		if(k==-1||s[i]==s[k])
		{
			i++;
			k++;
			nit[i]=k;
		}
		else
		{
			k=nit[k];
		}
	}
}
int main()
{
	int n;
	
	while(cin>>n)
	{
		string x;
		string s[10];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		cin>>x;
		getnext(x);
		int num=0;
		for(int k=0;k<n;k++)
		{
			int i=0,j=0;
			while(j<x.size())
			{
				if(s[k][i]==x[j])
				{
					i++;
					j++;
				}
				else if(i>=0)
				{
					i=nit[i];
				}
				else
				{
					j++;
					i=0;
				}
				if(i==s[k].size())
				{
					num++;
				}
			}
		}
		cout<<num<<endl;
	} 
} 
