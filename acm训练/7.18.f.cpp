/*给你一个整数N，你可以执行如下操作，

1：如果N能被2整除，用N/2代替N。

2：如果N能被3整除，用2N/3代替N。

3:  如果N能被5整除  用4N/5代替N。

你的任务是通过上述操作，求出将N变成1所需要的最小操作次数。

输入
输入第一行一个数字q，代表询问次数，1 < q < 100。

接下来q次询问，每次询问给出一个整数N  1 <= N <= 10^18。 


输出
对于每次询问，输出一个数并换行，如果能从N到1输出最小操作次数，否则输出 -1。*/
#include<cstdio>
using namespace std;
int main()
{
	int q,cnt;
	long long int n;
	scanf("%d",&q);
	while(q--)
	{
		cnt=0;
		scanf("%lld",&n);
		while(n%2==0||n%3==0||n%5==0)
		{
			if(n%2==0)
			{
				n/=2;
				cnt++;
			}
			if(n%3==0)
			{
				n/=3;
				cnt+=2;
			}
			if(n%5==0)
			{
				n/=5;
				cnt+=3;
			}
		}
		if(n==1)
		{
			printf("%d\n",cnt);
		}
		
		else printf("-1\n");
	}
	return 0;
}
