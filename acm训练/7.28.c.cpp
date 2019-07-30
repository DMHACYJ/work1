#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1005;
vector<int> v[maxn];
bool check[maxn];
int num[maxn];
int d[maxn];
bool spfa(int s)
{
	memset(check,false,sizeof(check));
	memset(num,0,sizeof(num));
	fill(d,d+maxn,INF);
	queue<int> q;
	q.push(s);
	check[s]=ture;
	num[s]++;
	d[s]=0;
	while(!q.empty())
 } 
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	return 0;
} 
