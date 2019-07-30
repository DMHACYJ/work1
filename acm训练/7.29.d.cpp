#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=30;
const int maxm=80;
struct edge
{
	int s,e;
	int co;
	friend bool operator < (edge a,edge b)
	{
		return a.co<b.co;
	}
}eg[maxm];
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
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<=n;i++)
		{
			pre[i]=i;
		} 
		int tot=0;
		for(int i=1;i<n;i++)
		{
			int k,co;
			char s,e;
			cin>>s>>k;
			while(k--)
			{
				cin>>e>>co; 
				eg[tot].s=s-'A';
				eg[tot].e=e-'A';
				eg[tot].co=co;
				tot++;
				eg[tot].s=e-'A';
				eg[tot].e=s-'A';
				eg[tot].co=co;
				tot++; 
			}
		}
		sort(eg,eg+tot);
		int res=0;
		for(int i=0;i<tot;i++)
		{
			if(find(eg[i].s)!=find(eg[i].e))
			{
				
				pre[find(eg[i].e)]=find(eg[i].s);
				res+=eg[i].co;
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
