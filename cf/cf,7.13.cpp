#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=631;
int n,q;
int a[maxn];
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i+n]);
			a[i]=a[i+n];
			a[i+2*n]=a[i+n];
		}
		int flag1=1;
		int flag2=1;
		for(int i=0;i<3*n-1;i++)
		{
			if(a[i]==a[i+1]-1)
			{
				flag1++;
			}
			else flag1=1;
			if(flag1==n) break;
		}
		for(int i=0;i<3*n;i++)
		{
			if(a[i]==a[i+1]+1)
			{
				flag2++;
			}
			else flag2=1;
			if(flag2==n)
			{
				break;
			}
		}
		if(flag1==n||flag2==n)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
} 
