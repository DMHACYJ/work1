/*
��Ŀ����
Michaelϲ����ѩ�Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������ 

1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����

����
����ĵ�һ�б�ʾ���������R������C(1 <= RC <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
���
��������ĳ��ȡ�*/
#include<iostream>
#include<cstring>
using namespace std;
int num[105][105];
int len[105][105];
int r,c;
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int x,int y)
{
	if(len[x][y]!=0)
	{
		return len[x][y];
	}
	int tx,ty,ms=0,s;
	for(int k=0;k<4;k++)
	{
		tx=dis[k][0]+x;
		ty=dis[k][1]+y;
		if(tx<0||tx>c-1||ty<0||ty>r-1)
		{
			continue;
		}
		if(num[tx][ty]<num[x][y])
		{
			s=dfs(tx,ty);
			ms=max(ms,s);
		}
	}
	len[x][y]=ms+1;
	return len[x][y];
}
int main()
{
	while(cin>>r>>c)
	{
		memset(len,0,sizeof(len));
		memset(num,0,sizeof(num));
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>num[i][j];
			}
		}
		int ms=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				ms=max(ms,dfs(i,j));
			}
		}
		cout<<ms<<endl;
	}
	return 0;
}
