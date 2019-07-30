#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long int a[1000];
	int n;
	while(cin>>n)
	{
		a[1]=1;
		a[2]=2;
		for(int i=3;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
		cout<<a[n]<<endl;
	}
	return 0;
}
