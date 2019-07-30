/*题目描述
红红在上体育课。今天体育老师不在，红红就有时间和同学们一起玩游戏了。

突然，红红发现，红红的面前有n个方格，每个方格上面写了一个数字。

红红突然想起了儿时的“跳房子”游戏。可是作为大学生，怎么能玩这么…低龄…的游戏呢！于是决定树立一个新的规则。


红红可以从方格外开始起跳。他每跳到一个格子上，就可以获得格子上数字那么多钱！但是他下一步跳到的格子上的数字必须比当前格子上的数字更大。

红红慌了，不知道他能拿到的钱是多少。聪明的你可以帮他计算一下吗？


输入
输入包含多组测试样例。每一个测试样例被如下描述：


N v1 v2 ... vN

保证对于每一个测试样例，N ≤ 1000，并且 vi 在32位整数范围内。

以0开头的测试样例作为输入终止标志，并且这组样例不被处理

输出
对于每一个测试样例，输出根据规则他最多可以获得的金额，每个测试样例一行。*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int num[1005];
int dp[1005];
int main()
{
	int n;
	while(cin>>n&&n)
	{
		memset(num,0,sizeof(num));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
		}
		dp[1]=num[1];
		for(int i=2;i<=n;i++)
		{
			dp[i]=num[i];
			for(int j=i-1;j>=1;j--)
			{
				if(num[i]>num[j])
				{
					dp[i]=max(dp[i],dp[j]+num[i]);
				}
			}
		}
		int ms=0;
		for(int i=1;i<=n;i++)
		{
			ms=max(dp[i],ms);
		}
		cout<<ms<<endl;
	}
	return 0;
}
