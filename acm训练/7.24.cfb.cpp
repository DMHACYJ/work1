#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 200000
int main()
{
	int q;
	int a[maxn];
	int n,k;
	cin>>q;
	while(q--)
	{
		cin>>n>>k;
		memset(a,0,sizeof(a));
		int cnt=0;
		int temp;
		for(int i=1;i<=n;i++)
		{
			cin>>temp;
			if(temp%2!=0)
			{
				a[cnt]=i;
				cnt++;
			}
		}
		if(cnt>=k)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<k;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
