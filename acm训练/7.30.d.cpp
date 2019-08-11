#include<iostream>
#include<cstring>
using namespace std;
const int maxn=11;
struct matrix
{
	int ju[maxn][maxn];
}c,f;
int k,m;
matrix mul_(matrix a,matrix b)
{
	matrix tmp;
	memset(tmp.ju,0,sizeof tmp.ju);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				tmp.ju[i][j]+=((a.ju[i][k]%m)*(b.ju[j][k]%m))%m;
				tmp.ju[i][j]%=m;
			}
		}
	}
	return tmp;
}
matrix jupoww(matrix a,int k)
{
	matrix ans;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(i==j)
			{
				ans.ju[i][j]=1;
			}
			else ans.ju[i][j]=0;
		}
	}
	while(k)
	{
		if(k&1)
		{
			ans=mul_(ans,a);
		}
		a=mul_(a,a);
		k>>=1;
	}
	return ans;
}
int main()
{
	while(cin>>k>>m)
	{
		memset(c.ju,0,sizeof c.ju);
		for(int i=0;i<10;i++)
		{
			cin>>c.ju[0][i];
			if(i<9)
			{
				c.ju[i+1][i]=1;
			}
			f.ju[9-i][0]=i;
		}
		if(k<10)
		{
			cout<<k<<endl;
		}
		else 
		{
            matrix tmp=jupoww(c,k-9);
            int ans=0;
            for(int i=0;i<10;i++)
			{
                ans=(ans+(tmp.ju[0][i]*f.ju[i][0])%m)%m;
            }
            cout<<ans<<endl;
		}
	}
	return 0;
}
