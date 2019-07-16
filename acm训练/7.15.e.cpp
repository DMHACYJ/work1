#include<cstdio> 
#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s;
	int temp,n;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>temp;
			s.insert(temp);
		}
		set<int> :: iterator i;
		for(i=s.begin();i!=s.end();i++)
		{
			if(i!=s.begin())
			{
				cout<<' ';
			}
			cout<<*i;
		}
		s.clear();
		cout<<endl;
	}
	return 0;
}
