#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point
{
	int x,y,z;
	point(){}
	point(int _x,int _y,int _z)
	{
		x=_x;
		y=_y;
		z=_z;
	}
	void input()
	{
		scanf("%d %d %d",&x,&y,&z);
	}
	point operator ^ (const point &b)const
	{
		return point(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
	}
	point operator - (const point &b)const
	{
		return point(x-b.x,y-b.y,z-b.z);
	}
	int operator * (const point &b)const
	{
		return x*b.x+y*b.y+z*b.z;
	}
}; 
point p[4];
int main()
{
	int t;
	cin>>t;
	for(int day=1;day<=t;day++)
	{
		for(int i=0;i<4;i++)
		{
			p[i].input();
		}
		point q=(p[1]-p[0])^(p[2]-p[0]);
		if((p[3]-p[1])*q==0)
		{
			cout<<"Day #"<<day<<": Yes"<<endl;
		}
		else cout<<"Day #"<<day<<": No"<<endl;
	}
	return 0;
} 
