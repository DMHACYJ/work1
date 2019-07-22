#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	stack<int> s;
	int num=0;
	int a[50000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		while(!s.empty()&&s.top()<=a[i]) 
		{
			s.pop();
		}
		
		if(s.empty())
		{
			s.push(a[i]);
		}
		else if(s.top()>a[i])
		{
			num+=s.size();
			s.push(a[i]);
		}
	}
	cout<<num<<endl;
	return 0;
}
