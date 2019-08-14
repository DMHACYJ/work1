#include<iostream>
#include<algorithm>
using namespace std;
const int maxa=410;
const int maxb=205;
int a[maxa];
int b[maxb];
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		int flag=0;
		scanf("%d",&n);
		for(int i=0;i<4*n;i++)
		{
			scanf("%d",&a[i]);
		}
		int bns=0;
		for(int i=0;i<4*n;i++)
		{
			for(int j=i+1;j<4*n;j++)
			{
				if(a[i]==a[j]&&a[i]&&a[j])
				{
					b[bns++]=a[i];
					a[i]=0;
					a[j]=0;
				}
			}
		}
//		if(bns==2*n)
//		{
			sort(b,b+2*n);
			for(int i=1,j=2*n-2;i<j;i++,j--)
			{
				if(b[i]*b[j]==b[i-1]*b[j+1])
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
//		}
		if(flag||n==1)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
