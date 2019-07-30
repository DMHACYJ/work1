#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	int num[30030];
	int dp[30030];
	while(cin>>n)
	{
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
			dp[i]=1;
		}
		for(int i=1;i<n;i++)
		{
			dp[i]=1;
			for(int j=i;j>=0;j--)
			{
				if(num[i]>num[j])
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
