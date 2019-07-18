#include<iostream>
#include<cstdio>
#include<cstring>

#include<algorithm>
using namespace std;
struct student
{
	string x;
	int time;
};
bool cmp(student a,student b)
{
	if(a.time>b.time||(a.time==b.time&&a.x<b.x)) return true;
	else return false;
}
struct student s[200];
int main()
{
	int n,h,m;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>s[i].x;
		    scanf("%d:%d",&h,&m);
		    s[i].time=h*60+m;
		}
		sort(s,s+n,cmp);
		cout<<s[0].x<<endl;
	}
	return 0;
}
