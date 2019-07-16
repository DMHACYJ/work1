#include<cstdio> 
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char temp,c;
	string ch;
	int sum=0,flag=0;
	vector<char> s;
	while(cin>>ch)
	{
		for(int i=0;i<ch.length();++i)
		{
			s.push_back(ch[i]);
		}
		cin>>c;
		vector<char>::iterator i;
		for(i=s.begin();i!=s.end();i++)
		{
			sum++;
			if(*i==c)
			{
				printf("%d ",sum);
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("NO");
		}
		printf("\n");
		sum=0;
		flag=0;
		s.clear();
	}
	return 0;
}
