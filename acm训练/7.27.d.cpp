#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int num[205];
	int sum[205][205];
	int dp[205][205];
	int n,x;
	sum[0][0]=0;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			fill(dp[i],dp[i]+sizeof(dp[i]),-0x3f3f3f3f);
			cin>>x;
			dp[i][i]=0;
			sum[i][i]=x;
		}
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				int j=i+len-1;
				for(int k=i;k<j;k++)
				{
					sum[i][j]=sum[i][j]+sum[k+1][j];
					
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);
				}
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
} 
