#include<iostream>
using namespace std;
typedef long long ll;
ll phi(ll x)
{
	ll ans=x;
	for(ll pi=2;pi*pi<=x;pi++)
	{
		if(x%pi==0)
		{
			ans=(ans/pi)*(pi-1);
			while(x%pi==0) x/=pi;
		}
	}
	if(x>1) ans=(ans/x)*(x-1);
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<phi(n)<<endl;
	}
	return 0;
}
