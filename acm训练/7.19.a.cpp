/*题目描述
现在有一些写着数字的卡片，我们定义一个规则：

两张数字相同的卡片是 OK 的，

三张连续数字的卡片是 OK 的，

给你一堆卡片，请你找出尽可能多的 OK 数，卡片不可以重复利用。

输入
多组输入，每组输入第一行为一个整数 n 表示卡片数量，1 ≤ n ≤ 1000000， n = 0 时输入结束。

接下来一行为 n 张卡片上的数字 x ，可能乱序。1 ≤ x ≤ 100 。

输出
输出卡片能凑出最多 OK 的数量。*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000000
int x[maxn];

int main()
{
	int n;
	
	while(cin>>n&&n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		sort(x,x+n);
		for(int i=0;i<n;i++)
		{
			if(x[i])
			{
				if(x[i]==x[i+1])
				{
					sum++;
				//	i++;
					x[i+1]=0;
				}				
				if((x[i]+1)==x[i+1]&&(x[i]+2)==x[i+2])
				{
					sum++;
				//	i+=2;
					x[i+1]=0;
					x[i+2]=0;
				}
				else if(x[i-3]&&(x[i-3]+1)==x[i]&&(x[i-3]+2)==x[i+1])
				{ 
					sum++;
				//	i++;
					x[i+1]=0;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
// 1 2 2 2 3
// 1 2 3 3 3
