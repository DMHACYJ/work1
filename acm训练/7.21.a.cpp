/*题目描述
    如题，给出n个字符串，让你输出其中共有多少个不同的字符串。
输入
第一行一个正整数n表示有n个字符串。

接下来n行每行一个字符串，每个字符串可以由数字和大小写字母组成，大小写敏感。

输出
输出一行包含一个整数，表示其中不同字符串的个数。*/
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
