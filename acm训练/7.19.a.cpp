/*��Ŀ����
������һЩд�����ֵĿ�Ƭ�����Ƕ���һ������

����������ͬ�Ŀ�Ƭ�� OK �ģ�

�����������ֵĿ�Ƭ�� OK �ģ�

����һ�ѿ�Ƭ�������ҳ������ܶ�� OK ������Ƭ�������ظ����á�

����
�������룬ÿ�������һ��Ϊһ������ n ��ʾ��Ƭ������1 �� n �� 1000000�� n = 0 ʱ���������

������һ��Ϊ n �ſ�Ƭ�ϵ����� x ����������1 �� x �� 100 ��

���
�����Ƭ�ܴճ���� OK ��������*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 1000000
int x[maxn];

int main()
{
	int n;
	
	while(cin>>n&&n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		sort(x,x+n);
		for(int i=0;i<n;i++)
		{
			if(x[i])
			{
				if(x[i]==x[i+1])
				{
					sum++;
				//	i++;
					x[i+1]=0;
				}				
				if((x[i]+1)==x[i+1]&&(x[i]+2)==x[i+2])
				{
					sum++;
				//	i+=2;
					x[i+1]=0;
					x[i+2]=0;
				}
				else if(x[i-3]&&(x[i-3]+1)==x[i]&&(x[i-3]+2)==x[i+1])
				{ 
					sum++;
				//	i++;
					x[i+1]=0;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
// 1 2 2 2 3
// 1 2 3 3 3
