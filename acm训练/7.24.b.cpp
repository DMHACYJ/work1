/*
题目描述
     学霸红红不但基础课学得好，敲代码敲得好，还有一个就是他喜欢夜观天象，和古代张衡不同的是，红红观测星星都喜欢将他们放在笛卡尔坐标系内观测。有一天红红和未来的大数学家可可一起夜观天象，红红用一张纸将他观测的所有星星都画在了同一二维直角坐标系内，他定义一颗星星左下方星星的数量为该星星的等级，现在他问可可给定星图上每个等级的星星数量。




例如，查看上图所示的地图，5号星的等级为3(左下方有1、2、4号星)，2号星和4号星的等级为1。在这张地图上有一颗0级的星星，两颗1级的星星，一颗2级的星星，和一颗3级的星星。

输入
输入的第一行包括了星星的数量N (1 ≤ N ≤ 15000)，下面N行描述了每颗星星的坐标(每一行由一个空格分隔两个整数X和Y组成 0 ≤ XY ≤ 32000)。每一个点只会存在一颗星星。星星以Y坐标的升序排列。Y坐标相等的恒星按X坐标的升序排列。
输出
输出应该包括N行，每行一个数字。第 i 行是等级为 i - 1的星星的数量( 1 ≤ i  ≤ n )。*/
#include<iostream>
#include<cstring>
using namespace std;
int n;
#define maxn 32032
int tree[maxn];
int ans[maxn];
int lowbit(int x)
{
	return x&(-x);
}
void updata(int i,int x)
{
	for(int j=i;j<=n;j+=lowbit(j))
	{
		tree[j]+=x;
	}
}
int getsum(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
int main()
{
	int x,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		//x+=1;
		ans[getsum(x)]++;
		updata(x,1);
	}
	for(int i=0;i<n;i++) 
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}

