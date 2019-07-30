#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[30030];
	int b[30030];
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		//fill(a,a+n,1);//填充函数，赋值为1，memset不能赋值1
		for(int i=0;i<n;i++)
		{
			b[i]=1;
			for(int j=0;j<i;j++)
			{
				if(a[i]<=a[j])
				{
					b[i]=max(b[j]+1,b[i]);
				}
			}
		} 
		int big=0;
		for(int i=0;i<n;i++)
		{
			big=max(big,b[i]);
		}
		cout<<n-big<<endl;
	}
	return 0;
}
