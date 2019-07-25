#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100000
int a[maxn];
int er[maxn][100];
void _er(int k,int x)
{
	int i=0;
	while(x/2)
	{
		er[k][i]=x%2;
		x=x/2;
		i++;
	}
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		memset(a,0,sizeof(a));
		cin>>n>>m;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		cout<<"Case #"<<i<<":"<<endl;
		while(m--)
		{
			int s;
			cin>>s;
			for(int j=1;j<n;j++)
			{
				ans=max(s^a[j],s^a[j+1]);
			}
			int k;
			for(k=1;k<n;k++)
			{
				if(s^a[k]==ans)
				{
					break;
				}
			}
			cout<<a[k]<<endl;
		}
	}
	return 0;
}
