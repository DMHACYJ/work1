#define  _CRT_SECURE_NO_WARNINGS
//#pragma pack(1)
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
//namespace N1
//{
//	int a;
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//}
//
////命名空间的嵌套
//namespace N2
//{
//	int b;
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//	namespace N3
//	{
//		int b;
//		int sub(int a, int b)
//		{
//			return a - b;
//		}
//	}
//}
//
////命名空间的分段定义
//namespace N1
//{
//	int b;
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//}
//
////命名空间成员访问方式： 
////                 1 ：命名空间名称 +  ：： + 变量名
////                 2 ：using + 命名空间名称 +  ：： + 变量名 --> 使用时不需要加作用域限定符
////                 3 : using namespace + 命名空间名称 --> 所有的成员全部暴露在全局域中-->不推荐-->会造成命名空间污染
//using N1::a;
//using N1::add;
////using namespace N1;
////using namespace N2;
//void test1()
//{
//	//命名空间成员访问方式： 命名空间名称 +  ：： + 变量名
//	//N1::a = 10;
//	a = 20;
//	//N1::sub(10, 5);
//	N1::sub(10, 5);
//	//嵌套
//	//N2::N3::b = 20;
//	N1::b = 30;
//	add(100, 200);
//}
////C++ 输入输出： <iostream>,  std
//using namespace std;
//void testIO()
//{
//	printf("hello world\n");
//	int a = 10;
//	printf("%d\n", a);
//	double d = 4.2;
//	/*std::cout << a;
//	std::cout << "\n";
//	std::cout << d;
//	std::cout << "\n";*/
//	/*std::cin >> a;
//	std::cout << "\n";
//	std::cout << a;
//	scanf_s("%d", &a);
//	std::cout << a;*/
//	//连续输入输出顺序：从左到右
//	cin >> a >> d;
//	cout << a << " " << d << endl;
//	
//}
//
//int main()
//{
//	testIO();
//	return 0;
//}


//void fun1(int a, int b)
//{
//	cout << a << b << endl;
//}
//缺省参数: 
//函数使用时：
//       不传参： 使用缺省值
//        传参： 使用实参值

//全缺省
//void fun1(int a = 100, int b = 0)
//{
//	cout << a << b << endl;
//}
//半缺省
//void fun1(int a, int b = 0)
//{
//	cout << a << b << endl;
//}
////半缺省： 缺省值必须从右到左连续赋值
//void fun2(int a, int b = 0, int c = 1)
//{
//	cout << a << b << c << endl;
//}
////缺省值：只能在一个地方定义， 声明或者定义
//void fun3(int a);
//
//void fun3(int a = 100)
//{
//	cout << a << endl;
//}
//
//
//int main()
//{
//	//fun1(10, 20);
//	/*fun1(1);
//	fun1(1, 2);
//	fun2(-1);
//	fun2(-1, 100);
//	fun2(-1, 100, 1000);*/
//	fun3();
//	return 0;
//}
//大前提： 函数属于同一个作用域
//函数重载： 函数名相同，参数信息不同：类型， 个数，顺序
// 参数信息： 参数类型不同
// 和函数的返回值无关， 返回值的类型不能区分函数

//int add(int a, int b)
//{
//	return a + b;
//}
//
//float add(float a, float b)
//{
//	return a + b;
//}
////不同的作用域不构成重载
//namespace N1
//{
//	float add(int a, float b)
//	{
//		return a + b;
//	}
//}
//
//// 参数信息： 参数个数不同
//
//int add(int a, int b, int c)
//{
//	return a + b + c;
//}
////参数信息： 参数类型顺序不同
//void Print(int a, char c)
//{
//	cout << a << " " << c << endl;
//}
//
//void Print(char c, int a)
//{
//	cout << c << " " << a << endl;
//}
////返回值类型不同不构成重载
////int Print(char c, int a)
////{
////	cout << c << " " << a << endl;
////	return a;
////}
//extern "C"  //按照C语言的规则编译  sub函数名---> 底层: _ +  函数名
//{
//	int sub(float a, int b);
//}
//
////int sub(float a, int b);
//
//
//int main()
//{
//	/*add(1, 2);
//	float a = 1.0, b = 2.0;
//	add(a, b);
//	add(1, 2, 3);*/
//	/*Print(10, 'a');
//	Print('a', 10);*/
//	sub(10, 5);
//	return 0;
//}

void testRef()
{
	int a = 10;
	int b = 20;
	//int类型引用 ra --> a 别名， ra --> a 的引用
	// 引用 --> 变量的别名
	int& ra = a;
	int& ra1 = a;
	int& ra2 = a;
	//引用类型必须初始化
	//int& ra3;
	int copya = a;

	ra = 100;  //  a --> 100
	ra = b; // ra, a, ra1, ra2 --> 20
	copya = 1000;  // a --> 100  ra ---> 100

	//常引用
	int c = 10;
	const int& rc = 10;
	const int d = 10;
	const int& rd = d;
	float f = 2.0;
	c = f;
	const int& rf = f;
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//引用做返回值，引用实体的声明周期 > 函数的生命周期
int& SelfAdd(int& a)
{
	a++;
	return a;
}

//int main()
//{
//	//testRef();
//	int a = 1, b = 2;
//	//Swap(&a, &b);  // a = 2, b =1
//	//Swap(a, b);  // a = 1, b = 2
//	int& ra = SelfAdd(a);
//	cout << "ra: " << ra << endl;
//	cout << "hello world" << endl;
//	int c = a + b;
//	cout <<"ra: "<< ra << endl;
//	return 0;
//}

//struct SA
//{
//	int arr[10000];
//};
//
//SA sa;
//
//void funSAValue(SA sa)
//{}
//
//void funSARef(SA& sa)
//{}
//
//
//SA funSAValueReturn()
//{
//	return sa;
//}
//
//SA& funSARefReturn()
//{
//	return sa;
//}
//
//
//
//void testRefValue(int n)
//{
//	size_t begin = clock();
//	for (int i = 0; i < n; ++i)
//		//funSAValue(sa);
//		funSAValueReturn();
//	size_t end = clock();
//	cout <<"Value:"<<  end - begin << endl;
//
//}
//
//void testRefRef(int n)
//{
//	size_t begin = clock();
//	for (int i = 0; i < n; ++i)
//		//funSARef(sa);
//		funSARefReturn();
//	size_t end = clock();
//	cout <<"Ref: "<< end - begin << endl;
//}
//
//void testRef2()
//{
//	int a = 10;
//	//底层实现上， 引用通过指针实现
//	//引用： 类型* const
//	int& ra = a;
//	ra = 100;
//	++ra;
//	sizeof(ra);
//	//int& rra;
//	//int& ---> int* const
//
//
//	int* pa = &a;
//	int* const cpa = &a;
//	int b = 20;
//	//cpa = &b;
//	++(*cpa) = 200;
//	sizeof(cpa);
//	int* pa1;
//}
//
////int main()
////{
////	int n;
////	cin >> n;
////	testRefValue(n);
////	testRefRef(n);
////	return 0;
////}
//
//int main()
//{
//	testRef2();
//	return 0;
//}

#define Fun(a, b) (a) * (b)
//inline函数不一定多展开，编译器会根据代码的复杂程度酌情展开
//inline int Mul(int a, int b)
//{
//	return a * b;
//}
#include "test2.h"

//inline int Mul(int a, int b);
//
//inline int Mul(int a, int b)
//{
//	return a * b;
//}

//int main()
//{
//	//int c = Fun(2, 3);  // 2 * 3
//	//cout << Fun(2 + 1, 3) << endl;
//	int d = Mul(2, 3);  // 2 * 3  call  Mul
//	d = Mul(2 + 1, 3);
//	return 0;
//}
//auto不能用于定义参数
//void fun(auto a)
//{}
//
//int main()
//{
//	//auto: 类型占位符
//	//auto定义变量，必须初始化
//	//      ：变量的实际类型通过初始化表达式确定
//	auto a = 10;
//	auto b = 2.0;
//
//	//auto c;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//
//	//指针类型
//	auto pa = &a;
//	auto* ppa = &a;
//	cout << typeid(pa).name() << endl;
//	cout << typeid(ppa).name() << endl;
//
//	//引用
//	auto& ra = a;
//	cout << typeid(ra).name() << endl;
//	
//
//	auto rra = a;
//	cout << typeid(rra).name() << endl;
//
//	ra = 1000;
//	int& rrra = a;
//	int copya = a;
//
//	auto e = 1, f = 2;
//
//	//auto不能用于定义数组
//	int ar[] = { 1, 2, 3 };
//	//auto arr[] = { 1, 3, 3 };
//	
// 
//	return 0;
//}

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	int* arr = (int*)malloc(sizeof(int)* 10);
//	int num = sizeof(arr) / sizeof(arr[0]); // num 1
//	/*for (int i = 0; i <= sizeof(a) / sizeof(a[0]); ++i)
//	{
//	cout << a[i] << endl;
//	}*/
//	//  当前遍历到的元素值  :  遍历的范围
//	for (int e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (const auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto& e : a)
//	{
//		e *= 2;
//	}
//	cout << endl;
//
//	for (const auto& e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//
//
//	return 0;
//
//}

//void fun(int a)
//{
//	cout << "fun(int a)" << endl;
//}
//
//void fun(int* a)
//{
//	cout << "fun(int* a)" << endl;
//}

//int main()
//{
//	int* p = NULL;
//	int* p2 = 0;
//	//nullptr 类型： nullptr_t
//	//nullptr可以进行隐式类型转换， 转成任意类型的指针空值
//	int* p3 = nullptr;
//	
//	fun(NULL);
//	fun((int*)NULL);
//	fun(nullptr);
//	cout << typeid(nullptr).name() << endl;
//	return 0;
//}
/*
struct 类名
{};
*/
// struct定义类：默认访问权限：公有
struct Student
{
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};

/*
class 类名
{};
*/
// class定义类：默认访问权限：私有
class Student2
{
	//public, private, protected： 只限制类外的访问权限
public:  // 成员在类外可见
	//成员函数
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
private:  //成员在类外不可见
	//成员变量: 在类内部具有全局属性，任何地方都可以访问到
	//         和访问限定符无关，和定义的位置也没有关系
	char _name[20];
	char _gender[3];
protected: // 成员在类外不可见
	int _age;

};

//类的声明
class Student3
{

public:
	//成员函数
	void SetStudentInfo(const char* name, const char* gender, int age);
	void PrintStudentInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;

};

//类的成员函数的定义： 需要加类的作用域
void Student3::SetStudentInfo(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
//普通函数： 不能访问类的私有成员
//void SetStudentInfo(const char* name, const char* gender, int age)
//{
//	strcpy(_name, name);
//	strcpy(_gender, gender);
//	_age = age;
//}

void Student3::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}

//public, private, protected

//int main()
//{
//	//struct, class 定义的类唯一的区别就是成员的默认访问权限不同
//	//类的实例化： 定义一个类类型的变量
//	//类类型的变量 : 类的对象
//	Student st;
//	st._age = 18;
//	st.SetStudentInfo("helo", "man", 18);
//	st.PrintStudentInfo();
//
//	Student2 st2;
//	st2.SetStudentInfo("helo", "man", 10);
//	st2.PrintStudentInfo();
//	return 0;
//}

class A
{
	int a;
};

class B
{
	int b;
	void fun(int a, int b)
	{
		int c = a + b;
	}
};
class C
{

};

class D
{
public:
	char c;
	double d;
	int a;
};

//int main()
//{
//	//类对象的大小和结构体大小计算规则相同
//	//A a;
//	//B b;
//	//C c;
//	////对象中只存放成员变量
//	//int sz = sizeof(a);
//	////成员函数不存放在对象中
//	//sz = sizeof(b);
//	////空类的大小为1
//	//sz = sizeof(c);
//	D d;
//	int sz = sizeof(d);
//	cout << ((char*)&d.a - (char*)&d) << endl;
//	return 0;
//}

union F
{
	int a;
	char c;
};
int main()
{
	F f;
	f.a = 1;
	int b = 1;
	char c = b;
	int* pb = &b;
	char* pbb = (char*)pb;
	if (f.c == 0)
	{
		cout << "big end" << endl;
	}
	else
	{
		cout << "little end" << endl;
	}

	if (*pbb == 0)
	{
		cout << "big end" << endl;
	}
	else
	{
		cout << "little end" << endl;
	}

	return 0;
}


