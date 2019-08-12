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
	int line_cross_seg(line v)
	{
		int d1=sgn((e-s)^(v.s-s));
		int d2=sgn((e-s)^(v.e-s));
		if((d1^d2)==-2) return 2;
		return (d1==0||d2==0);
	}
};
line l[105];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int flag=0;
		if(n<=2) flag=1;
		for(int i=0;i<n;i++)
		{
			point s,e;
			s.input();
			e.input();
			l[i]=line(s,e);
		}
		for(int i=0;i<n&&!flag;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				line l1=line(l[i].s,l[j].s);
				line l2=line(l[i].s,l[j].e);
				line l3=line(l[i].e,l[j].s);
				line l4=line(l[i].e,l[j].e);
				int k;
				int flag1=0,flag2=0,flag3=0,flag4=0;
				for(k=0;k<n;k++)
				{
					if(!l1.line_cross_seg(l[k])) 
					{
						flag1=1;
						break;
					}
				}
				for(k=0;k<n;k++)
				{
					if(!l2.line_cross_seg(l[k])) 
					{
						flag2=1;
						break;
					}
				}
				for(k=0;k<n;k++)
				{
					if(!l3.line_cross_seg(l[k])) 
					{
						flag3=1;
						break;
					}
				}
				for(k=0;k<n;k++)
				{
					if(!l4.line_cross_seg(l[k])) 
					{
						flag4=1;
						break;
					}
				}
				if(!flag1||!flag2||!flag3||!flag4)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag) cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
	}
	return 0;
}
