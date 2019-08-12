#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-8;
int sgn(double x)
{
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}
struct point
{
	double x, y;
	point(){}
	point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	double operator ^ (const point &b)const
	{
		return x*b.y-y*b.x;
	}
	point operator - (const point &b)const
	{
		return point(x - b.x, y - b.y);
	}
};
struct line
{
	point s, e;
	line(){}
	line(point _s, point _e)
	{
		s = _s;
		e = _e;
	}
	int relation(point p)
	{
		int c = sgn((p-s)^(e-s));
		if(c == 0) return 1;
		else return 0;
	}
};
int main()
{
	double xa, xb, xc, ya, yb, yc;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	point a = point(xa, ya);
	point b = point(xb, yb);
	point c = point(xc, yc);
	line p = line(a, b);
	if(p.relation(c))
	{
		printf("You\'re so funny\n");
	}
	else
	{
		printf("%.2f",fabs((b-a)^(c-a))/2);
	}
	return 0;
} 
