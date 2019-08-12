#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-8;
const int maxp=1010;
int sgn(double x)
{
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;
	else return 1; 
}
struct point
{
	double x,y;
	point(){}
	point(double _x,double _y)
	{
		x=_x;
		y=_y;
	}
	void input()
	{
		scanf("%lf %lf",&x,&y);
	}
	double operator ^ (const point &b)const
	{
		return x*b.y-y*b.x;
	}
	point operator - (const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
}; 
struct line
{
	point s,e;
	line(){}
	line(point _s,point _e)
	{
		s=_s;
		e=_e;
	}
	void input(double y1,double y2)
	{
		double x1,x2;
		scanf("%lf %lf",&x1,&x2);
		s.x=x1;
		s.y=y1;
		e.x=x2;
		e.y=y2;
	}
	int relation(point p)
	{
		int c=sgn((p-s)^(p-e));
		if(c<0) return 1;
		else if(c>0) return 2;
		else return 3;
	}
};
point p[maxp];
line l[maxp];
int main()
{
	int n,m;
	double x1,x2,y1,y2;
	int result[maxp];
	int sum[maxp];
	memset(result,0,sizeof(result));
	memset(sum,0,sizeof(sum));
	scanf("%d %d %lf %lf %lf %lf",&n,&m,&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)
	{
		l[i].input(y1,y2);
	}
	for(int i=0;i<m;i++)
	{
		p[i].input();
	}
	sum[0]=0;
	sum[n+1]=m;
	for(int ans=1;ans<=n;ans++)
	{
		for(int i=0;i<m;i++)
		{
			if(l[ans].relation(p[i])==1)
			{
				sum[ans]++;
			}
		}
	}
	for(int i=n+1;i>0;i--)
	{
		result[i-1]=sum[i]-sum[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		cout<<i<<": "<<result[i]<<endl;
	}
	return 0;
}
