#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=200000;
int issu[maxn];
int vis[maxn];
void Prime(int n)
{
	int cnt=0;
	memset(vis,0,sizeof vis);
	vis[0]=1;
	vis[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			issu[cnt++]=i;
			for(int j=i+i;j<=n;j+=i)
			{
				vis[j]=1;
			}
		}
	}
}
int pre[maxn]; 
void getpre(int n)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;	
		}
		pre[i]=cnt;
	}
}
int main()
{
	Prime(maxn);
	getpre(maxn);
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<pre[b]-pre[a-1]<<endl;
	}
	return 0;
}
