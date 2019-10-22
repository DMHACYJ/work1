#include<iostream>
using namespace std;
class A {
public:
	A() {
		cout << "A()" << endl;
	}
};

class Date {
public:
	//没有显示定义构造的时候，编译器会默认生成，
	//如果已经显示定义了，编译器不会再去生成
	//默认构造：（默认构造函数只能有一个）不一定非要有，不调用就行了
	//				1.无参构造
	//             2.编译器默认生成的
	//             3.全缺省的构造函数
	//一般会定义一个全缺省的构造函数
	/*Date() {
		cout << "Date()" << endl;
	}*/
	Date(int year=2000, int month=1, int day=1) {//全缺省：默认构造
		this->_year = year;
		this->_month = month;
		_day = day;
	}
	//构造函数重载
	Date(int year = 2000, int month = 1) {
		this->_year = year;
		this->_month = month;
		_day = 1;
	}
	//const& :可以接受任何类型的Date对象，临时对象也可以接收
	//        & :只能接收非临时的Date对象
	//参数类型如果为值会无限递归
	Date(const Date& d)//拷贝构造，传入的参数必须是引用类型，如果传值会无限递归，语法错误
	{
		_year = d._year;
		_month = d._month;
			// 若未显示定义，系统生成默认的拷贝构造函数。 
			//默认的拷贝构造函数对象按内存存储按字节序完成拷贝,相当于memcpy()
			//这种拷贝我们叫做浅拷贝，或者值拷贝。
		_day = d._day;
		cout << "Date(const Date& date)" << endl;
	}

	/*
		运算符重载函数：
		函数名： operator + 要重载的运算符
		其他的和普通函数定义相同

	*/
	bool operator==(const Date& d2)//第一个参数是this，编译器隐式传递
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	/*
		this指针：类类型 * const
			 指向当前函数调用的对象的指针--->谁调用指向谁
			 作为成员函数的第一个参数
			 只存在于成员函数中
	*/
	//void SetDate(Date* cosnt this, int year, int month, int day)
	void SetDate(int year, int month, int day) {
		this->_year = year;
		this->_month = month;
		_day = day;
	}

	void Display() {
		cout <<this-> _year << "-" << this->_month << "-" << this->_day << endl;
	}
	//析构函数完成对象资源清理，整个生命周期值调用一次：销毁对象之前，本身不销毁对象
	//析构函数会自动调用自定义类型的析构函数
	~Date() {
		cout << "~Date()" << endl;
	}
private:
	//编译器默认生成的构造函数：
	//		内置类型：无操作
	//		自定义类型：会调用自定义类型的默认构造函数，完成自定义类型的初始化

	//所有的构造函数都会自动调用自定义类型的默认构造函数
	int _year;
	int _month;
	int _day;
	A _a;
};

class String {
public:
	String(const char *str = "") {
		_str = (char*)malloc(strlen(str) + 1);//编译器不主动消灭malloc申请的空间
		strcpy(_str, str);
	}
	//如果有资源，显式定义析构完成资源清理，否则会有内存泄漏
	~String() {
		if (_str) {
			cout << "~String()" << endl;
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};