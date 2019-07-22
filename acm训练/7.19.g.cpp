#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000
int F[maxn];
int J[maxn];
double Y[maxn];
int m,n;
int check(double mid)
{
	for(int i=0;i<n;i++)
	{
		Y[i]=F[i]-mid*J[i];
	}
	sort(Y,Y+n);
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=Y[n-1-i];
	}
	return sum>=0;
}
int main()
{
	while(cin>>m>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>F[i]>>J[i];
		}
		double l=0,r=maxn,mid;
		for(int i=0;i<100;i++)
		{
			mid=(l+r)/2;
			if(check(mid))l=mid;
			else r=mid;
		}
		cout<<l*m<<endl;
	}
	return 0;
}
/*��Ŀ����
���׼����m������׼�������һ���Ǯ�Թ��Լ���������룬������n����꣬��i����������ҪJ[i]�����⣬���ȫ�����������Ի��F[i]���𣬵�Ȼ������ѡ����ĳ�����ֻ����һ���֣��������������ܻ�ö�������
����
�����һ�а�������������m��n�ֱ��ʾ����ʼӵ�е�����Ľ������������

������n�У�ÿ�а��������������ֱ��ʾ�� i ������F[i] �� J[i]����˼����Ŀ��������֤����������С��1000.

���
���һ������������ʾ����ܻ�õ����������������С�������λ��*/
