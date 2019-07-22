/*题目描述
给出一个n≤1000000的数组。有一个大小为 k 的滑动窗口，它从数组的最左边移动到最右边。你只能在窗口看到k个数字。每次滑动窗口向右移动一个位置。比如：

The array is [1 3 -1 -3 5 3 6 7] and k is 3.



要求输出在k 范围内的最大和最小值

输入
输入由两行组成。

第一行包含两个整数n和k，它们是数组和滑动窗口的长度。第二行有n个整数。



输出
输出中有两行。

第一行分别从左到右给出窗口中每个位置的最小值。

第二行给出最大值。*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 10000+4 
struct node
{
	int num,i; 
}a[maxn];

int num[maxn];
void get_max(int n,int m)
{	
	int head=1,tail=1;
	for(int i=0;i<=n;i++)
	{
		a[i].num=a[i].i=0;
	}
	a[0].num=0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		while(head<=tail&&a[tail].num<=num[i]) tail--;
		a[++tail].num=num[i];
		a[tail].i=i;
	}
	for(int i=m;i<=n;i++)
	{
		while(head<=tail&&a[tail].num<=num[i]) tail--;
		
		a[++tail].num=num[i];
		a[tail].i=i;
		
		if(a[head].i<=i-m) 
		{
			head++;
		}
		cout<<a[head].num<<" ";
	}
}
void get_min(int n,int m)
{	
	int head=1,tail=1;
	for(int i=0;i<=n;i++)
	{
		a[i].num=a[i].i=0;
	}
	a[0].num=-0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		while(head<=tail&&a[tail].num>=num[i]) tail--;
		a[++tail].num=num[i];
		a[tail].i=i;
	}
	for(int i=m;i<=n;i++)
	{
		while(head<=tail&&a[tail].num>=num[i]) tail--;
		
		a[++tail].num=num[i];
		a[tail].i=i;
		
		if(a[head].i<=i-m) 
		{
			head++;
		}
		cout<<a[head].num<<" ";
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	get_min(n,m);
	cout<<endl;
	get_max(n,m);
	return 0;
	
}
