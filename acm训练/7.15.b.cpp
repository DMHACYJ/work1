#include<list>
#include<cstdio>
using namespace std;
int main()
{
	list<int> s;
	int n,m;
	while(1)
	{
		scanf("%d %d",&n,&m);
		if(n==0&m==0)
		{
			break;
		}
		s.clear();
		for(int i=1;i<=n;i++)
		{
			s.push_back(i);
		}
		list<int>::iterator it=s.begin();
		while(s.size()>1)
		{
			for(int i=1;i<m;i++)
			{
				it++;
				if(it==s.end()) it=s.begin();
			}
			it=s.erase(it);
			if(it==s.end()) it=s.begin();
		}
		printf("%d\n",s.front());
	}
	return 0;
}
