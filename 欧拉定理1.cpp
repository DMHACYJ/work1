#include<iostream>
using namespace std;
typedef long long ll;
ll poww(ll x,ll y,ll c)
{
	ll result=1;
	while(y>0)
	{
		if(y&1)
		{
			result=((result%c)*(x%c))%c;
		}
		x=((x%c)*(x%c))%c;
		y=y>>1;
	}
	return result%c;
}
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
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		ll x=phi(c);
		if(gcd(a,c)==1)
		{
			cout<<poww(a,b%x,c)<<endl;
		}
		else if(b<x)
		{
			cout<<poww(a,b,c)<<endl;
		}
		else cout<<poww(a,(b%x)+x,c)<<endl;
	}
	return 0;
}
