/*题目描述
佳星最近开了一家专营苹果派的店，开店以来生意火爆，所以他打算扩大规模。为了做好扩大规模的准备工作，他进了一大批的苹果。

但是扩大规模后发现他进的苹果太多了，一时间卖不完，但是果农现在已经没有苹果了，也就是说，接下来他只能靠剩下的苹果过活，但是周期问题导致苹果对苹果派的味道加成不一样。

苹果派的味道即苹果味道加成总和， 即 如果三个苹果加成的味道分别为 1， -1， 3 那苹果派最后的味道为3

但是今天客户下单的苹果派他不小心把苹果拿出来拿多了，所以他需要拿掉一部分苹果，但是他希望尽可能的保持苹果派的味道变化小，所以现在需要你编写一个程序来计算苹果派的味道问题。如果变化程度相同，比如去掉一个苹果有， 苹果派的味道原来是 12， 有一个苹果是1， 另一个苹果是 -1， 则选择去掉-1那个，苹果派味道变成13，即使得苹果派的味道在变化最小的情况下尽可能变得味道更好， 当然，优先变化最小。

输入
有多组输入样例

第一行包括一个n ，m (  0< m < n  <=100000) n 是苹果总数，m是需要拿掉的苹果数量

第二行有n 个数字，表示每个苹果对苹果派的味道加成( -100<= a[i] <= 100)

输出
输出拿掉m个苹果后味道变化最小的味道总和*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 100000
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
		for(i=0;i<n;i++)
		{
			if(a[i]>=0)
			{
				break;
			}
		}
		int num;
		for(int j=i-1,k=i,num=0;num<m;num++ )
		{
			if(j>=0&&(-a[j])<=a[k])
			{
				a[j]=0;
				j--;
			}
			else
			{
				a[k]=0;
				k++;
			}
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(a[i])
			{
				sum=sum+a[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
