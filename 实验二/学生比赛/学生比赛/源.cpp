#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	Student() {}
	Student(const char* sno, char* name ,int grade) {
		strcpy(_sno, sno);
		strcpy(_name, name);
		_grade = grade;
		_sumGrade += grade;
	}

	void toString() {
		cout << "¿¼ºÅ£º"<< _sno << "  ÐÕÃû£º" << this->_name << "  ³É¼¨£º" << _grade << endl;
	}

	static int getSumGrade() {
		return _sumGrade;
	}
	~Student() {
		delete[] _sno;
		delete[] _name;
	}
private:
	char _sno[10];
	char _name[10];
	int _grade;
	static int _sumGrade;
};
int Student::_sumGrade = 0;

int main() {
	char sno1[] = { "01" };
	char name1[] = {"dmh"};
	char sno2[] = { "01" };
	char name2[] = { "dmh" };
	char sno3[] = { "01" };
	char name3[] = { "dmh" };

	Student s1(sno1, name1, 100);
	Student s2(sno2, name2, 100);
	Student s3(sno3, name3, 100);

	s1.toString();
	s2.toString();
	s3.toString();

	cout << s1.getSumGrade() << endl;

	getchar();
	return 0;
}