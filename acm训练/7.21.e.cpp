/*题目描述
红红的棚子里养着一群兔子。
有一天，红红想要研究兔子的 DNA 序列和兔子的长相。
首先选取一个好长好长的 DNA 序列（小兔子是外星生物，DNA 序列可能包含 26 个小写英文字母）。
然后每次选择两个区间，询问如果用两个区间里的 DNA 序列分别生产出来两只兔子，这两个兔子是否一模一样。
注意两个兔子一模一样只可能是他们的 DNA 序列一模一样。

请使用字符串hash

输入
第一行输入一个 DNA 字符串 S。

第二行一个数字 m，表示 m 次询问。

1 ≤length(S)m≤1000000

接下来 m 行，每行四个数字 L1 R1 L2 R2，分别表示此次询问的两个区间，注意字符串的位置从1开始编号。


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
const int base = 131;   //进制
char ch[maxn];
ULL h[maxn], p[maxn];   //h数组是求前缀哈希值，p数组是求进制的i次幂

ULL get(int l, int r)   //求一段区间的哈希值
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	// freopen("C:\\Users\\LOZCY\\Desktop\\test\\data.txt", "r", stdin);       //设置 cin scanf 这些输入流都从 test.in中读取
	// freopen("C:\\Users\\LOZCY\\Desktop\\test\\text2.txt", "w", stdout);     //设置 cin scanf 这些输入流都从 test.in中读取

	scanf(" %s", ch + 1);
	memset(h, 0, sizeof h);
	int n = strlen(ch + 1); //从ch[1]开始存
	p[0] = 1;
	for (int i = 1; i <= n; i++) 
	{
		h[i] = h[i - 1] * base + ch[i] - 'a' + 1; //利用前缀和的思想求哈希值
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


