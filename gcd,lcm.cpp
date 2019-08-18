#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
const int maxn=100;
long long int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
long long int lcm(int a,int b)
{
	return (a/gcd(a,b))*b;
}
int a[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof a);
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int x=gcd(a[0],a[1]);
		int y=lcm(a[0],a[1]);
		for(int i=2;i<n;i++)
		{
			x=gcd(a[i],x);
			y=lcm(a[i],y);
		}
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
