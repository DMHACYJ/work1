/*题目描述
若某个家族人员过于庞大，要判断两个是否是亲戚，确实不容易，给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果xy是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚
输入
第一行：三个整数nmp，（n< =5000m< =5000p< =5000）
分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数
mi 和mj ，表示他俩有亲戚关系
具有亲戚关系。
接下来p行：每行两个数
 Pi 和 Pj，询问 Pi和 Pj是否具有亲戚关系。
输出
共P行，每行一个’Yes’或’No’。表示第Pi 个询问的答案为“有”或“没有”亲戚关系。*/
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 5000
int n,m,p;
int pre[maxn];
int Find(int root)
{
	int son=root,temp;
	while(root!=pre[root])
	{
		root=pre[root];
	} 
//	while(son!=root)
//	{
//		temp=pre[son];
//		pre[son]=root;
//		son=root;
//	}
	return root;
}
int main()
{
	int mi,mj;
	cin>>n>>m>>p;
	for(int i=1;i<n;i++)
	{
		pre[i]=i;
	}
	while(m--)
	{
		cin>>mi>>mj;
		mi=Find(mi);
		mj=Find(mj);
		if(mi!=mj)
		{
			pre[mi]=mj;
		}
	}
	while(p--)
	{
		int pi,pj;
		cin>>pi>>pj;
		if(Find(pi)==Find(pj))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		
		}
	}
} 
