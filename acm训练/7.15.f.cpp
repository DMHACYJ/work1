#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;
int main()
{
	int n;
	int sum=0;
	string temp;
	set<string> s;
	while(cin>>n)
	{
		while (n--)
		{
			cin>>temp;
			s.insert(temp);
		}
		set<string> :: iterator i;
		for(i=s.begin();i!=s.end();i++)
		{
			sum++;
		}
		cout<<sum<<endl;
		sum=0;
		s.clear();
	}
	return 0;
} 
