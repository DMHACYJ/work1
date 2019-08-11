#include<iostream>
#include<cmath>
using namespace std;
const int mod=1000000009;
typedef long long ll;
ll poww(ll a,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1) res=(res*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	ll n;
	while(cin>>n)
	{
		cout<<(4*poww(3,n-2))%mod<<endl;
	}
	return 0;
} 
