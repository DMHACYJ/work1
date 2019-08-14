#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1000010;
int num[25][maxn];
int n;
void st()
{
	int x=(int)(log((double)n)/log(2.0));
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j+(1<<(i-1))-1<=n;j++)
		{
			cout<<x<<n<<endl;
			num[i][j]=max(num[i-1][j],num[i-1][j+(1<<(j-1))]);
		}
	}
}
int rmq(int l,int r)
{
	int k=int(log((double)(r-l+1))/log(2.0));
	return max(num[k][l],num[k][r-(1<<k)+1]);
}
int main()
{
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[0][i]);
	}
	st();
	while(m--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		cout<<rmq(l,r)<<endl;
	}
	return 0; 
}
