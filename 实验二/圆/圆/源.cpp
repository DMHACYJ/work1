#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdlib>
using namespace std;
const double Pi = cos(-1);

class Circle {
public:
	Circle(float r) {
		_radius = r;
	}

	double Circumference() {//计算周长
		return 2 * Pi * _radius;
	}

	double CircumArea() {//计算面积
		return Pi * _radius*_radius;
	}

private:
	float _radius;
};

int main() {
	float radius;
	cout << "Enter the radius of the pool" << endl;
	cin >> radius;
	while (radius <= 0) {
		cout << "Input again" << endl;
		cin >> radius;
	}
	Circle pool(radius);
	Circle poolFence(radius + 3);
	cout << "Fense cost: ";
	cout << poolFence.Circumference() * 35 << endl;
	cout << "Concret cost is: ";
	cout << (poolFence.CircumArea() - pool.CircumArea()) * 3 << endl;
	system("pause");
	return 0;
}