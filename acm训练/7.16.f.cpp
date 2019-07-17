#include<iostream>
using namespace std;
int fun(int n,int m)
{
	if(n==1)
	{
		return m;
	}
	return fun(n-1,(m+1)*2);
}
int main()
{
	
	int n,m,t;
	while(cin>>n>>m>>t)
	{
		printf("%d\n",t*fun(n,m));
	}
	return 0;
}
