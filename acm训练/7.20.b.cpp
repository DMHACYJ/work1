#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int mp[6][6];
void init_map()
{
	for(int i=1;i<6;i++)
	{
		for(int j=i;j<6;j++)
		{
			if(j==4&&i<3||i==j)
			{
				mp[i][j]=0;
			}
			else
			{
				mp[i][j]=1;
			}
			mp[j][i]=mp[i][j];
		}
	}
}

/*int check()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(mp[i][j]!=0)
			{
				return 0;
			}
		}
	}
	return 1;
}
int step[15];
int nu;
void _step(int now,int x)
{
	step[nu++]=now;
	if(check()==0)
	{
		init_map();
		nu=0;
		for(int i=0;i<nu;i++)
		{
			cout<<step[i];
		}
		printf("\n");
		return;
	}
	int i,j;
	for(i=1;i<=8;i++)
	{
		for(j=x;j<=5;j++)
		{
			if(mp[now-1][j-1])
			{
				mp[now-1][j-1]=0;
				mp[j-1][now-1]=0;
				now=j;	
				_step(j,1);
			}
			
		}
		if(j==6)
		{
			mp[now-1][j-1]=1;
			mp[j-1][now-1]=1;
			x=now+1;
		}
	}
}
int main()
{
	init_map();
	nu=0;
	_step(1,1);
	return 0;
}*/
void dfs(int x,int k,string s)
{
	s+=char(x+'0');
	if(k==8)
	{
		cout<<s<<endl;
	}
	for(int i=1;i<=5;i++)
	{
		if(mp[x][i])
		{
			mp[x][i]=mp[i][x]=0;
			dfs(i,k+1,s);
			mp[x][i]=mp[i][x]=1;
		}
	} 
}
int main()
{
	init_map();
	dfs(1,0,"");
	return 0;
}
