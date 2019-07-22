#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
string s;
int h;
 
int main()
{
	stack<int> q;
	cin>>h>>s;
	int i=0;
	
	q.push(i);
	while(!q.empty())
	{
		i=q.top();
		cout<<s[i];
		q.pop();
		for( ;i<s.size();)
		{
			i=2*i+1;
			cout<<s[i];
			if((2*i+1)<s.size())
			{
				q.push(i+1);
			}
			else 
			{
				cout<<s[i+1];	
			}
		}
	}
	return 0;
} 
