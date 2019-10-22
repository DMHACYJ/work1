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
	cout << (d1 == d2) << endl;
}

int main() {
	//testConstruct();
	testString();
	getchar();
	return 0;
}