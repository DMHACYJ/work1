/*��Ŀ����
��������������һȺ���ӡ�
��һ�죬�����Ҫ�о����ӵ� DNA ���к����ӵĳ��ࡣ
����ѡȡһ���ó��ó��� DNA ���У�С�������������DNA ���п��ܰ��� 26 ��СдӢ����ĸ����
Ȼ��ÿ��ѡ���������䣬ѯ������������������ DNA ���зֱ�����������ֻ���ӣ������������Ƿ�һģһ����
ע����������һģһ��ֻ���������ǵ� DNA ����һģһ����

��ʹ���ַ���hash

����
��һ������һ�� DNA �ַ��� S��

�ڶ���һ������ m����ʾ m ��ѯ�ʡ�

1 ��length(S)m��1000000

������ m �У�ÿ���ĸ����� L1 R1 L2 R2���ֱ��ʾ�˴�ѯ�ʵ��������䣬ע���ַ�����λ�ô�1��ʼ��š�


#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int m;
	cin>>m;
	while(m--)
	{
		int num=0;
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		for(int i=l1-1,j=l2-1;i<r1,j<r2;i++,j++)
		{
			if(s[i]==s[j])
			{
				num++;
			}
		}
		if(num==r1-l1+1&&num==r2-l2+1)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn = 1000010;
const int base = 131;   //����
char ch[maxn];
ULL h[maxn], p[maxn];   //h��������ǰ׺��ϣֵ��p����������Ƶ�i����

ULL get(int l, int r)   //��һ������Ĺ�ϣֵ
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	// freopen("C:\\Users\\LOZCY\\Desktop\\test\\data.txt", "r", stdin);       //���� cin scanf ��Щ���������� test.in�ж�ȡ
	// freopen("C:\\Users\\LOZCY\\Desktop\\test\\text2.txt", "w", stdout);     //���� cin scanf ��Щ���������� test.in�ж�ȡ

	scanf(" %s", ch + 1);
	memset(h, 0, sizeof h);
	int n = strlen(ch + 1); //��ch[1]��ʼ��
	p[0] = 1;
	for (int i = 1; i <= n; i++) 
	{
		h[i] = h[i - 1] * base + ch[i] - 'a' + 1; //����ǰ׺�͵�˼�����ϣֵ
		p[i] = p[i - 1] * base;
	}
	int m;
	cin >> m;
	while (m--) 
	{
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		if (get(l, r) == get(x, y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}


