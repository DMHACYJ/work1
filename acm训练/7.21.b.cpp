/*
题目描述
赵神最近在做一份兼职——帮人查一串字符串中某个单词的出现次数。


当工作太多时，赵神就忙不过来啦，所以他想找一名助手帮他。

输入
第一行输入一个 T ，代表数据数目。


每组数据第一行输入需要查找的单词。

第二行输入这个较长的字符串（长度小于1000010）。

输出
每组数据输出一个 n ，代表要这个单词出现的次数。*/
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
