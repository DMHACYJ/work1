#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100;
long double p[maxn];
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>p[i];
	}
	sort(p,p+t);
	long double result=0;
	int i;
	for(i=t-1;i>=0;i--)
	{
		result+=1/(1+p[i]);
		if(result>1)
		{
			break;
		}
	}
	cout<<t-i-1<<endl;
	return 0;
}
