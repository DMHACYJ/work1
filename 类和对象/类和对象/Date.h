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
	//û����ʾ���幹���ʱ�򣬱�������Ĭ�����ɣ�
	//����Ѿ���ʾ�����ˣ�������������ȥ����
	//Ĭ�Ϲ��죺��Ĭ�Ϲ��캯��ֻ����һ������һ����Ҫ�У������þ�����
	//				1.�޲ι���
	//             2.������Ĭ�����ɵ�
	//             3.ȫȱʡ�Ĺ��캯��
	//һ��ᶨ��һ��ȫȱʡ�Ĺ��캯��
	/*Date() {
		cout << "Date()" << endl;
	}*/
	Date(int year=2000, int month=1, int day=1) {//ȫȱʡ��Ĭ�Ϲ���
		this->_year = year;
		this->_month = month;
		_day = day;
	}
	//���캯������
	Date(int year = 2000, int month = 1) {
		this->_year = year;
		this->_month = month;
		_day = 1;
	}
	//const& :���Խ����κ����͵�Date������ʱ����Ҳ���Խ���
	//        & :ֻ�ܽ��շ���ʱ��Date����
	//�����������Ϊֵ�����޵ݹ�
	Date(const Date& d)//�������죬����Ĳ����������������ͣ������ֵ�����޵ݹ飬�﷨����
	{
		_year = d._year;
		_month = d._month;
			// ��δ��ʾ���壬ϵͳ����Ĭ�ϵĿ������캯���� 
			//Ĭ�ϵĿ������캯�������ڴ�洢���ֽ�����ɿ���,�൱��memcpy()
			//���ֿ������ǽ���ǳ����������ֵ������
		_day = d._day;
		cout << "Date(const Date& date)" << endl;
	}

	/*
		��������غ�����
		�������� operator + Ҫ���ص������
		�����ĺ���ͨ����������ͬ

	*/
	bool operator==(const Date& d2)//��һ��������this����������ʽ����
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
		thisָ�룺������ * const
			 ָ��ǰ�������õĶ����ָ��--->˭����ָ��˭
			 ��Ϊ��Ա�����ĵ�һ������
			 ֻ�����ڳ�Ա������
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
	//����������ɶ�����Դ����������������ֵ����һ�Σ����ٶ���֮ǰ���������ٶ���
	//�����������Զ������Զ������͵���������
	~Date() {
		cout << "~Date()" << endl;
	}
private:
	//������Ĭ�����ɵĹ��캯����
	//		�������ͣ��޲���
	//		�Զ������ͣ�������Զ������͵�Ĭ�Ϲ��캯��������Զ������͵ĳ�ʼ��

	//���еĹ��캯�������Զ������Զ������͵�Ĭ�Ϲ��캯��
	int _year;
	int _month;
	int _day;
	A _a;
};

class String {
public:
	String(const char *str = "") {
		_str = (char*)malloc(strlen(str) + 1);//����������������malloc����Ŀռ�
		strcpy(_str, str);
	}
	//�������Դ����ʽ�������������Դ������������ڴ�й©
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