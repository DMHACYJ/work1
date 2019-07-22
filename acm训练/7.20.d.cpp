#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000

int a[maxn]; 
int main()
{
	int n,m;
	
	while(cin>>n>>m)
	{
	
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		int i;
		for(i=n-1;i>=0 ;i--)
		{
			if((m-=a[i])>0)
			{
				continue;
			}
			else 
			{
				
				m=a[i];
				break;
			}
		}
		if(i==-1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int j;
		for(j=0;j<=i;j++)
		{
		
			if(m==a[j])
			{
			
				cout<<"YES"<<endl;
				break;
			}
		}
		if(j==i+1)
		{
			cout<<"NO"<<endl;
			continue;
		}
	}
	return 0;	
}
