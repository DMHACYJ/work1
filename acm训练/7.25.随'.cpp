#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int cnt=0;
		int temp;
		while(n--)
		{
			cin>>temp;
			cnt^=temp;
		}
		if(cnt==0)
		{
			cout<<"second"<<endl;
		}
		else
		{
			cout<<"first"<<endl;
		}
	}
	return 0;
}
