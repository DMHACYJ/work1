/*
题目描述
左左有N串长度比较短的牛肉串，俊俊有一串长度比较长的牛肉串。牛肉串都是由字符组成，俊俊想知道左左的每一串牛肉串在自己的牛肉串中出现的次数。

输入
输入多组数据。

输入一个数字N代表左左的N串牛肉串。1 <= N <= 10。

接下来N行为左左的牛肉串中的字符。字符串长度不超过10。

第N+1行，俊俊的牛肉串中的字符。字符串长度不超过100。

输出
输出一个数字代表左左的N串牛肉串在俊俊的牛肉串中出现的次数。*/
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
