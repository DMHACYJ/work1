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
	cout << (d1 == d2) << endl;
}

int main() {
	//testConstruct();
	testString();
	getchar();
	return 0;
}