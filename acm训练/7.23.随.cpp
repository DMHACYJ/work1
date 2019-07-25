/*
题目描述
在XX号到XX号之间，分数最高的是几分
输入
本题目包含多组测试，请处理到文件结束
在每个测试的第一行，有两个正整数 N 和 M ( 0<N<=200<M<10 )，分别代表学生的数目和询问次数

学生ID编号分别从1编到N

第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩

剩下M行每行有两个数字，询问ID从A到B(包括AB)的学生当中，成绩最高的是多少

输出
对于每一次询问操作，在一行里面输出最高成绩*/
#include<iostream>
using namespace std;
struct tree
{
	int l;
	int r;
	int grade;
}stu[200];
int num[200];
void build(int k,int l,int r)
{
	stu[k].l=l;
	stu[k].r=r;
	if(l==r)
	{
		stu[k].grade=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	stu[k].grade=max(stu[k<<1].grade,stu[k<<1|1].grade);
}

int get_max(int k,int l,int r)
{
	int res=0;
	if(l<=stu[k].l&&r>=stu[k].r) return stu[k].grade;
	int mid=(stu[k].r+stu[k].l)>>1;
	if(l<=mid) res=max(res,get_max(k<<1,l,r));
	if(r>mid) res=max(res,get_max(k<<1|1,l,r));
	return res;
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
		}
		build(1,1,n);
		int a,b;
		while(m--)
		{
			cin>>a>>b;
			cout<<get_max(1,a,b)<<endl;
		}
	}
	return 0;
} 
