/*题目描述
        红红马上过生日了，他打算买n块蛋糕用来庆祝生日，假设n块蛋糕都为圆柱形，他们的底面圆的半径不一定相等但是他们的高都相等且为1，他邀请了F个人参加他的生日Party，保证每个人都能来，现在他想把这n块蛋糕等体积的分给包括他的参加聚会的所有人，为了保证蛋糕的颜值，他想每块蛋糕只能被切开但是不能重新组合，现在问你每个人最大能分到多大的蛋糕， 结果保留至小数点后四位。
输入
输入第一行为一个整数t，表示样例数。

对于每个样例，输入第一行包括两个正整数n，F分别表示红红打算买蛋糕的数目以及红红邀请的客人数。

数据保证(1 ≤ n，F ≤ 10000）。每组测试样例的第二行包括n个正整数，分别表示n块蛋糕的半径r，每两个整数之间有一个空格。(1 ≤ r ≤ 10000)。

输出
对于每组测试样例，请输出每个人能分到的蛋糕的最大体积，回答为一个浮点数，精确到小数点后四位。*/
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define maxn 10000
#define pi acos(-1)
int n,f;
int d[maxn];

int check(double mid)
{
	int num=0;
	for(int i=0;i<n;i++)
	{
		num+=(int)(pow(d[i],2)/pow(mid,2));
	}
	return num>=f+1;//加红红自己 
}
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n>>f;
		for(int i=0;i<n;i++)
		{
			cin>>d[i];
		}
		double l=0,r=maxn,mid;
		for(int i=0;i<100;i++)
		{
			mid=(l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%.4lf\n",pow(l,2)*pi*10000/10000);
	}
} 
