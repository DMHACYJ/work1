/*
题目描述
某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。

省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。即 1-2 2-3 也可以认为1与3 是联通的

问最少还需要建设多少条道路？ 


输入
测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( <= 10000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
注意:两个城市之间可以有多条道路相通也就是说
3 3
1 2
1 2
2 1

这种输入也是合法的
当N为0时，输入结束，该用例不被处理。 */
#include<iostream>
using namespace std;
#define maxn 10000
int pre[maxn];
int Find(int root)
{
	int son=root,temp;
	while(root!=pre[root])
	{
		root=pre[root];
	}
	return root;
}
int main()
{
	int n,m;
	while(cin>>n)
	{
		if(n==0) return 0;
		cin>>m;
		int num=n;
		for(int i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		while(m--)
		{
			int mi,mj;
			cin>>mi>>mj;
			mi=Find(mi);
			mj=Find(mj);
			if(mi!=mj)
			{
				pre[mi]=mj;
				num--;
			}	
		}
		cout<<num-1<<endl;
		
	}
	return 0;
}
