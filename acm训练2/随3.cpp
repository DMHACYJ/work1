/*
��Ŀ����
��1�ˡ�2�ˡ�...��n�˵������һö���ܳƳ��ļ����������ܹ��м��ֿ��ܷ�����

����
�ж������룬ÿ�����һ������n��0 < n < 1000��
���
��ÿ��������������� ��������n���ܷ�����m
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a=(1+n)*n/2;
		cout<<a<<" "<<pow(2,n)-1<<endl;
	}
	return 0;
} 
