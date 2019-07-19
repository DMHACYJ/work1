#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int ans[40000];
int main()
{
	memset(ans,0,sizeof(ans));
	int n;
	int sum; 
	int yu;
	while(cin>>n)
	{
		ans[0]=1;
		int tot=1;
		int j;
		for(int i=2;i<=n;i++)
		{
			yu=0;
	
			for( j=0;j<tot;j++)
			{
				sum=yu+i*ans[j];
				ans[j]=sum%10;
				yu=sum/10;
				
			}
			while(yu)
			{
				ans[tot]=yu%10;
				yu=yu/10;
				tot++;
			}
			
		}
		while(tot--)
		{
			cout<<ans[tot];
		}
		cout<<endl;
	}
	return 0;
} 
/*
1   1
2   2
3   6


*/







