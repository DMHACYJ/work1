#include <iostream>
#include <cstdio>
using namespace std;
long long int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
long long int lcm(int a,int b)
{
	return (a/gcd(a,b))*b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
	}
	return 0;
}

