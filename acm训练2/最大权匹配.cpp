#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=307;
const int inf=0x3f3f3f3f;
int n;
int linker[maxn],lx[maxn],ly[maxn];
int slack[maxn];
bool visx[maxn],visy[maxn];
int score[maxn][maxn];
bool dfs(int x) 
{
    visx[x] = true;
    for(int y = 0; y < n; y ++) 
	{
        if(visy[y]) continue;
        int tmp = lx[x] + ly[y] - score[x][y];
        if(tmp == 0) 
		{
            visy[y] = true;
            if(linker[y] == -1 || dfs(linker[y])) 
			{
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp) slack[y] = tmp;
	}
	return false;
}
int km()
{
	memset(linker,-1,sizeof linker);
	memset(ly,0,sizeof ly);
	for(int i=0;i<n;i++)
	{
		lx[i]=-inf;
		for(int j=0;j<n;j++)
		{
			if(score[i][j]>lx[i]) lx[i]=score[i][j];
		}
	}
	for(int x=0;x<n;x++)
	{
		for(int i=0;i<n;i++) slack[i]=inf;
		while(1)
		{
			memset(visx,false,sizeof visx);
			memset(visy,false,sizeof visy);
			if(dfs(x)) break;
			int d=inf;
			for(int i=0;i<n;i++)
			{
				if(!visy[i]&&d>slack[i]) d=slack[i];
			}
			for(int i=0;i<n;i++)
			{
				if(visx[i]) lx[i]-=d;
			}
			for(int i=0;i<n;i++)
			{
				if(visy[i]) ly[i]+=d;
				else slack[i]-=d;
			}
		}
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(linker[i]!=-1) res+=score[linker[i]][i];
	}
	return res;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>score[i][j];
		}
	}
	cout<<km()<<endl;
	return 0;
} 
