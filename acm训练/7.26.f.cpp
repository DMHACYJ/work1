#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int d[1010];
	int dp[1010];
	while(cin>>n&&n)
	{
		memset(d,0,sizeof(d));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>d[i];
		}
		int p;
		cin>>p;
		sort(d+1,d+n+1);
		if(p<5)
		{
			cout<<p<<endl;
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				for(int j=p-5;j>=d[i];j--)
				{
					dp[j]=max(dp[j],dp[j-d[i]]+d[i]);
				}
			}
			cout<<p-dp[p-5]-d[n]<<endl;
		}
	}
	return 0;
}
