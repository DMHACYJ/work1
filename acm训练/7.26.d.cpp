#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int w[3403];
	int d[3403];
	int dw[13000];
	memset(dw,0,sizeof(dw));
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>d[i];
	}
	int j;
	for(int i=1;i<=n;i++)
	{
		for(j=m;j>=w[i];j--)
		{
			dw[j]=max(dw[j],dw[j-w[i]]+d[i]);
		}
	}
	cout<<dw[m]<<endl;
	return 0;
}
