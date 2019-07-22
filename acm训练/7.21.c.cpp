/*
题目描述
小林最近开始研究算命。


虽然他不会算命，但是他可以自己创造一个算命的算法。


当一个人的名字的前缀，与另一个人的名字后缀，相同的字母越多，这两个人就越有可能成为情侣。（此处前后缀可以包括名字本身）。


这个算姻缘的方法使得许多妹子前来测试。然而，由于他最近忙着写线段树，没空帮人算姻缘啦。


这里还有许多没测完呢。你能帮帮美丽的妹子们算算吗？


输入
输入有多组数据。


每组数据有两行，分别为两个人的名字（名字全由英文组成，名字长度不超过50000）。*/
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int nit[100000];
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		int len=a.size();
		a=a+b;
		int k=-1;
		int i=0;
		nit[0]=-1;
		while(i<a.size())
		{
			if(k==-1||a[i]==a[k]&&k<len)
			{
				k++;
				i++;
				nit[i]=k;
			}
			else 
			{
				k=nit[k];
			} 
		}
		for(i=0;i<k;i++)
		{
			cout<<a[i];
			if(i==k-1)
			{
				cout<<" ";
			}
		}
		cout<<k<<endl;
	}
	return 0;
}
