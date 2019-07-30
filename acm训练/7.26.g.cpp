#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	int x[101];
	int k[101];
	int xk[100010];
	while(cin>>n)
	{
		memset(x,0,sizeof(x));
		memset(k,0,sizeof(k));
		memset(xk,0,sizeof(xk));
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>k[i];
		}
		int m;
		cin>>m;
		int j;
		for(int i=1;i<=n;i++)
		{
			for(j=k[i];j<=m;j++)
			{
				xk[j]=max(xk[j],xk[j-k[i]]+x[i]);
			}
		}
		cout<<xk[m]<<endl;
	}
	return 0;
}
