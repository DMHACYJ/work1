/*��Ŀ����
    ���⣬����n���ַ���������������й��ж��ٸ���ͬ���ַ�����
����
��һ��һ��������n��ʾ��n���ַ�����

������n��ÿ��һ���ַ�����ÿ���ַ������������ֺʹ�Сд��ĸ��ɣ���Сд���С�

���
���һ�а���һ����������ʾ���в�ͬ�ַ����ĸ�����*/
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int n;
	string temp;
	set<string> s;
	cin>>n;
	while(n--)
	{
		cin>>temp;
		s.insert(temp);
	}
	cout<<s.size()<<endl;
	return 0;
} 
