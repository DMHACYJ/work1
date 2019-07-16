#include<cstdio> 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n,i,temp,sum=0;
	queue<int> a,b;
	while(cin>>n)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",&temp);
			a.push(temp);
		}
		for(i=0;i<n;++i)
		{
			scanf("%d",&temp);
			b.push(temp);
		}
		while(!a.empty())
		{
			if(a.front()==b.front())
			{
				sum+=2;
				a.pop();
				b.pop();
			}
			else
			{
				a.pop();
			}
		}
		printf("%d\n",sum);
		while(!a.empty()) a.pop();
		while(!b.empty()) b.pop();
		sum=0;
	}
	
	return 0;
} 
