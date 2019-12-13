#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const double PI = cos(-1);

class Circle 
{ 
public:  
    Circle(double r) {
		radius = r; 
	} 
    virtual double area() { 
		return 0.0; 
	} 
    virtual double volume() {
		return 0.0; 
	} 
protected: 
	double radius; 
}; 
class Sphere : public Circle 
{  
public: 
    Sphere(double r) : Circle(r) {
	} 
    double area() { 
		return 4.0 * PI * radius * radius; 
	} 
    double volume() { 
		return 4.0 * PI * radius * radius * radius / 3.0; 
	} 
}; 
class Column : public Circle 
{  
public: 
    Column(double r,double h) : Circle(r) {
		height = h; 
	} 
    double area() { 
		return 2.0 * PI * radius * ( height + radius ); 
	} 
    double volume() { 
		return PI * radius * radius * height; 
	} 
private: 
    double height; 
}; 
int main() {   
    Sphere sphere(1);  
    cout << "球体：" << endl; 
    cout << "体积：" << sphere.volume() << endl; 
    cout << "表面积：" << sphere.area() << endl; 
    Column column(1, 1);  
    cout << "圆柱体：" << endl; 
    cout << "体积：" << sphere.volume() << endl; 
    cout << "表面积：" << sphere.area() << endl;
    return 0; 
}
