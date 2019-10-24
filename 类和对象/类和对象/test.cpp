#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

//void testDate() {
//	Date d;//实例化
//	d.SetDate(2019, 10, 22);
//	d.Display();
//
//	Date d2;
//	d2.SetDate(2019, 10, 22);
//	d2.Display();
//}
//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout <<this-> _a << endl;//这里this的地址为空，因为调用此方法的对象为空，不能解引用
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;//不需要解引用的时候，空的实例化对象也可以编过
//	}
//private:
//	int _a;
//};
//
//int main() {
//	//testDate();
//	A* p = NULL;
//	p->PrintA();
//	p->Show();
//	return 0;
//}

void testConstruct() {
	//无参构造函数后面无需加括号
	Date d(2019, 29,90);//构造函数在实例化时编译器自动调用，整个生命周期只调用一次
	//实例化对象的时候必须要调用默认构造
	//d.SetDate(2019, 10, 23);
	//Date d3();//这是一个函数声明

	Date d2(2019, 10, 25);
}

void testString() {
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	String s("hello");//"hello"为临时对象不能被修改，所以用的String默认构造函数的参数要加"const"
							//否则语法错误
//	String copy(s);  //此时String的s自动调用了释放空间的析构函数,再使用时出错，还是要自己写copy函数
	cout << (d1.Equal( d2)) << endl;

	//const
	const Date d4(2019, 10, 24);//const（只读）对象只能调用const的成员方法
	d4.Display();

	//取地址
	Date* pd = &d1;
	const Date* pd1 = &d4;
}

class C {
public:
	C(int c)
		//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，
		//与其在初始化列表中的先后次序无关
		:_c(c)
		, _a(2 * c)
	{
	}

	C() {
	}
private:
	//C++ 11：相当于缺省值（初始化）只针对非静态成员
	int _c = 1;
	int _a = 2;
};

//int dcount; 
class D {
public:
	//支持单参构造函数的隐式类型转换
	/*explicit*/ D(int d) //explicit禁止隐式类型转换
		: _d(d)
	{
		++dcount;
	}

	D(const D& d)
		: _d(d._d)
	{
		++dcount;
	}

	D& operator = (const D& d) {
		_d = d._d;
		return *this;
	}

	static int getCount() {
		//_d = 20;静态成员函数只能访问静态成员
		return dcount;
	}
private: 
	int _d;
	//static成员：所有对象共享，属于类成员
	static int dcount;
};
//static静态成员必须在类外初始化
int D::dcount = 0;

D fun(D d) {
	return d;
}

int main() {
	//testConstruct();
	//testString();

	C c(10);

	//单参构造函数的隐式类型转换
	D dobj = 10;
	dobj = 20;
	//static成员的访问形式：对象访问，或者类名+作用域
	int *pd = &dobj.getCount;

	fun(dobj);
	cout << sizeof(dobj) << endl;
	getchar();
	return 0;
}