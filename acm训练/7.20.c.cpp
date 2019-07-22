#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
	int next;
}node[100];

int main()
{
	int n,m;
	int i,j;
	int sum=0;
	cin>>n>>m;
	for(int k=1;k<=m;k++)
	{
		cin>>i>>j;
		node[i].next=j;
		node[j].next=0;
	}
	int k=1;
	for(int q=1;q<=n;q++)
	{
		for( ;q<=n; )
		{
			if(node[q].next)
			{
				q=node[q].next;
				node[k].next=0;
			}
			else 
			{
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
