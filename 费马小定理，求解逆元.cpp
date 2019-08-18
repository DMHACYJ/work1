#include<iostream>
#include<cmath>
using namespace std;
const int p=19260817;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long int result=1;
		cin>>n;
		int x=p-2;
		while(x--)
		{
			result=((n%p)*(result%p))%p;
		}
		cout<<result<<endl;
	}
	return 0;
}
