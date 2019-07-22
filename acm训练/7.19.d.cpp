/*题目描述
红红买了一张从a市飞到c市的机票，不幸的是，没有直飞航班。但有很多从a市到b市，从b市到c市的航班。

从a市到b市有n个航班，它们在时刻a1，a2，a3 ……an起飞，经过ta时间后到达b市。

从b市到c市有n个航班，它们在时刻b1，b2，b3……bm起飞，经过tb时间后到达c市。

转机的时间可以忽略不计，所以所以当且仅当bj≥ai+ta时，可以从a市到b市的i次飞行和从b市到c市的j次飞行。

你最多可以取消k次航班。如果你取消了航班，红红就不能使用它。

红红想要尽可能早地进入c市，而你想让他尽可能晚地进入c市。

如果你最优地取消了k次航班，输出红红到达c的最早时间。

如果你可以取消k个或更少的航班，并且使红红无法到达c市，请输出- 1。

输入
第一行包含5个整数  n m ta tb k （n和m小于等于2e5）

第二行包含n个不同的数  a1  a2  a3 …… an  （保证递增，且保证在int范围内）

第二行包含m个不同的数 b1  b2  b3 …… bn  （保证递增，且保证在int范围内）


输出
如果你可以取消k个或更少的航班，并且使红红无法到达c市，请输出- 1。

如果你最优地取消了k次航班，输出红红到达c的最早时间。*/
#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 200000
int a[maxn];
int b[maxn];

int lower(int l,int r,int n){
  while(l<=r){

    int mid=(l+r)/2;
    if(n>b[mid]) l=mid+1;
    else r=mid-1;
  }
  return l;
}
int main()
{
	int n,m,ta,tb,k;
	cin>>n>>m>>ta>>tb>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]+=ta;
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	if(k>=min(n,m))
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int ans=0;	
	for(int i=0;i<=k;i++)
	{
		int p=lower(0,m-1,a[i]);
		p+=k-i;
		if(p>=m)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		ans=max(ans,b[p]+tb);
	}
	cout<<ans<<endl;
	return 0;
} 


