#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1005;
int pre[maxn];
int find(int root)
{
	while(1)
	{
		if(root==pre[root])
		{
			return root;
		}
		root=pre[root];
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			pre[i]=i;
		}
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			if(find(a)!=find(b))
			{
				pre[find(a)]=find(b);
				num++;
			}
		}
		cout<<n-num-1<<endl;
	}
	return 0;
}
