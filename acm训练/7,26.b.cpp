#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int a[20020];
	int b[20020];
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		fill(a,a+n,1);//填充函数，赋值为1，memset不能赋值1
		for(int j=1;j<=n;j++)
		{
			for(int i=0;i<n-1;i++)
			{
				if(a[j]>a[i])
				{
					b[j]=max(b[j],b[i]+1);
				}
			}
		} 
		int big=1;
		for(int i=0;i<n;i++)
		{
			big=max(big,b[i]);
		}
		cout<<big-1<<endl;
	}
	return 0;
}
