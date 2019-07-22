#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n;
char t[100];
void tree(int i)
{
	if(i>=n)
	{
		return;
	}
	printf("%c",t[i]);
	tree(2*i+1);
	tree(2*i+2);
}
int main()
{
	int h;
	cin>>h>>t;
	n=int(pow(2,h))-1;
	tree(0);
	cout<<endl;
	return 0;
}
