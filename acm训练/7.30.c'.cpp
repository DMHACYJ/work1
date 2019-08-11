#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string.h>
using namespace std;
const int mod=1000000009;
long long a[3][3],b[3][3],c[3][3],d[3][3];
void fun (long long e[][3],long long f[][3],long long g[][3])
{
	long long i,j,k,l,m,n,x,y;
	for (i=1;i<=2;i++)
	{
		for (j=1;j<=2;j++)
		{
			for (y=0,k=1;k<=2;k++)
			{
				y+=e[i][k]*f[k][j]%mod;
			}
			g[i][j]=y%mod;
		}
	}
}
long long fei(long long n)
{
	long long i,j,k,l,m;
	while (n)
	{
		if (n&1)
		{
			fun(a,c,b);
			for (i=1;i<=2;i++)
				for (j=1;j<=2;j++)
					c[i][j]=b[i][j];
		}
		fun(a,a,b);
		for (i=1;i<=2;i++)
			for (j=1;j<=2;j++)
				a[i][j]=b[i][j];
		n>>=1;
	}
	return c[1][2];
}
int main()
{
	long long i,j,k,l,m,n,x,y;
	cin>>n;
	for (i=1;i<=2;i++)
	{
		for (j=1;j<=2;j++)
		{
			a[i][j]=1;
		}
	}
	a[2][2]=0;
	c[1][1]=1;
	c[1][2]=0;
	c[2][1]=0;
	c[2][2]=1;
	cout<<fei(n)<<endl;
}
