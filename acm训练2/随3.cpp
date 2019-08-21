/*
题目描述
有1克、2克、...、n克的砝码各一枚，能称出哪几种重量？总共有几种可能方案？

输入
有多组输入，每组读入一个数字n（0 < n < 1000）
输出
对每组输入输出两个数 称重种数n，总方案数m
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
