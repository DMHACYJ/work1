#include<iostream>
using namespace std;
typedef long long ll;
ll ktl(ll n)
{
	if(n==0||n==1) return 1;
	ll ret=0;
	for(int i=0;i<n;++i)
	{
		ret+=ktl(i)*ktl(n-1-i);
	}
	return ret;
}
int main()
{
	ll n;
	while(cin>>n)
	{
		ll ni=1;
		for(int i=2;i<=n;i++)
		{
			ni=ni*i;
		}
		cout<<ktl(n)*ni*ni<<endl;
	}
	return 0;
}
