#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=150015;
int sum[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int temp;
		scanf("%d",&temp);
		sum[temp]++;
	}
	int result=0;
	for(int i=1;i<maxn;i++)
	{
		if(sum[i]==1)
		{
			result++;
		}
		else if(sum[i]==2)
		{
			result+=2;
		}
		else if(sum[i]>=3)
		{
			if(i==1)
			{
				result+=2;
			}
			else result+=3;
		}
	}
	cout<<result<<endl;
	return 0;
} 
