#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

//void testDate() {
//	Date d;//ʵ����
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
//		cout <<this-> _a << endl;//����this�ĵ�ַΪ�գ���Ϊ���ô˷����Ķ���Ϊ�գ����ܽ�����
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;//����Ҫ�����õ�ʱ�򣬿յ�ʵ��������Ҳ���Ա��
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
	//�޲ι��캯���������������
	Date d(2019, 29,90);//���캯����ʵ����ʱ�������Զ����ã�������������ֻ����һ��
	//ʵ���������ʱ�����Ҫ����Ĭ�Ϲ���
	//d.SetDate(2019, 10, 23);
	//Date d3();//����һ����������

	Date d2(2019, 10, 25);
}

void testString() {
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	String s("hello");//"hello"Ϊ��ʱ�����ܱ��޸ģ������õ�StringĬ�Ϲ��캯���Ĳ���Ҫ��"const"
							//�����﷨����
//	String copy(s);  //��ʱString��s�Զ��������ͷſռ����������,��ʹ��ʱ��������Ҫ�Լ�дcopy����
	cout << (d1.Equal( d2)) << endl;

	//const
	const Date d4(2019, 10, 24);//const��ֻ��������ֻ�ܵ���const�ĳ�Ա����
	d4.Display();

	//ȡ��ַ
	Date* pd = &d1;
	const Date* pd1 = &d4;
}

class C {
public:
	C(int c)
		//��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳��
		//�����ڳ�ʼ���б��е��Ⱥ�����޹�
		:_c(c)
		, _a(2 * c)
	{
	}

	C() {
	}
private:
	//C++ 11���൱��ȱʡֵ����ʼ����ֻ��ԷǾ�̬��Ա
	int _c = 1;
	int _a = 2;
};

//int dcount; 
class D {
public:
	//֧�ֵ��ι��캯������ʽ����ת��
	/*explicit*/ D(int d) //explicit��ֹ��ʽ����ת��
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
		//_d = 20;��̬��Ա����ֻ�ܷ��ʾ�̬��Ա
		return dcount;
	}
private: 
	int _d;
	//static��Ա�����ж������������Ա
	static int dcount;
};
//static��̬��Ա�����������ʼ��
int D::dcount = 0;

D fun(D d) {
	return d;
}

int main() {
	//testConstruct();
	//testString();

	C c(10);

	//���ι��캯������ʽ����ת��
	D dobj = 10;
	dobj = 20;
	//static��Ա�ķ�����ʽ��������ʣ���������+������
	int *pd = &dobj.getCount;

	fun(dobj);
	cout << sizeof(dobj) << endl;
	getchar();
	return 0;
}