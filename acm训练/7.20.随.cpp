#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int main()
{
	int num=0;
	cin>>a>>b;
	int i=0,j;
	for( ;i<a.size();i++)
	{
		int sum=0;
		for(j=0;j<b.size();j++)
		{
		
			if(b[j]==a[i])
			{
				sum++;
			}
			else
			{
				i-=sum-1;
				break;
			}
			if(sum==b.size())
			{
				num++;
				i+=2;
			}
		}
	}
	cout<<num<<endl;
	return 0;
}
