#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string a,b,tmp;
	while(cin>>a>>b)
	{
		int dp[a.size()+5][b.size()+5];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<a.size();i++)
		{
			int k=i+1;
			for(int j=0;j<b.size();j++)
			{
				int l=j+1;
				if(a[i]==b[j])
				{
					dp[k][l]=dp[k-1][l-1]+1;
				}
				else
				{
					dp[k][l]=max(dp[k][l-1],dp[k-1][l]);
				}
			}
		}
		cout<<dp[a.size()][b.size()]<<endl;
	}
	return 0;
}
