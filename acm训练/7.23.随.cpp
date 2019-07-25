/*
��Ŀ����
��XX�ŵ�XX��֮�䣬������ߵ��Ǽ���
����
����Ŀ����������ԣ��봦���ļ�����
��ÿ�����Եĵ�һ�У������������� N �� M ( 0<N<=200<M<10 )���ֱ����ѧ������Ŀ��ѯ�ʴ���

ѧ��ID��ŷֱ��1�ൽN

�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�

ʣ��M��ÿ�����������֣�ѯ��ID��A��B(����AB)��ѧ�����У��ɼ���ߵ��Ƕ���

���
����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�*/
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
