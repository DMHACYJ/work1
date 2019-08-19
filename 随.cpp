/*题目描述
现在有 n 盏灯，每盏灯有一个开关，编号从 1~n。

如果灯是关着的，摁一次开关就会打开。

如果灯是开着的，摁一次开关就会关闭。

目前所有灯都是关闭的。

现在有 n 个人，每个人都有一个编号，分别为 1 ~ n。

n 个人轮流摁下自己编号的倍数号码的开关。

问最后还有多少盏灯是亮着的。

输入
第一行输入 一个 T。

接下来 T 行，每行一个数字 n，表示有 n 盏灯。

(0 < T < 100，0 < n < 264)

输出
每组样例输出一个数字，表示最后亮着的灯的个数。*/
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll; 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<int(sqrt(n))<<endl;
	}
	return 0;
}
