/*ì³²¨ÄÇïÆ¹«Ê½*/
#include<iostream>
#include<cmath>
using namespace std;
const int mod=1000000009;
const long long maxn=1000000000000000000;
typedef long long ll;
ll fib(ll n)
{
	double sq=sqrt(5);
	return int((pow(1+sq,n)-pow(1-sq,n))/(pow(2.0,n)*sq));
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n)%mod<<endl;
	return 0;
}
