#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn =100010;
//const ll p = 1e9+7;
ll n,m,p;
ll fac[maxn];
ll poww(ll n, ll m,ll p)
{
	ll res=1;
	while(m)
	{
		if(m%2!=0)
		{
			res*=n;
			res%=p;
		}
		n*=n;
		n%=p;
		m/=2;
	}
	return res;
}
ll C(ll n,ll m,ll p)
{
	if(m>n) return 0;
	if(n==m) return 1;
	if(m>n-m) m=n-m;
	return fac[n]*poww(fac[m]%p,p-2,p)%p*poww(fac[n-m]%p,p-2,p)%p;
}
ll lucas(ll n,ll m,ll p)
{
	if(m==0)
		return 1;
	return lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;	
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>p;
		fac[0]=1;
		for(int i=1;i<=p;++i)
		{
			fac[i]=fac[i-1]*i%p;
		}
		cout<<lucas(n,m,p)<<endl;	
	} 
	return 0;
}
