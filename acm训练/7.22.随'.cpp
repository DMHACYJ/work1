/*��Ŀ����
����һ��n��1000000�����顣��һ����СΪ k �Ļ������ڣ����������������ƶ������ұߡ���ֻ���ڴ��ڿ���k�����֡�ÿ�λ������������ƶ�һ��λ�á����磺

The array is [1 3 -1 -3 5 3 6 7] and k is 3.



Ҫ�������k ��Χ�ڵ�������Сֵ

����
������������ɡ�

��һ�а�����������n��k������������ͻ������ڵĳ��ȡ��ڶ�����n��������



���
����������С�

��һ�зֱ�����Ҹ���������ÿ��λ�õ���Сֵ��

�ڶ��и������ֵ��*/
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
