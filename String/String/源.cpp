#include<iostream>
#include<list>
#include<string>
using namespace std;
//string    basic_string<char>
//typedef basic_string<char, char_traits, allocator> string

void testString1() {
	string s;
	string s2("hello world");
	string copy(s2);
	string s3(s2, 0, 5);//hello
	string s4("hello world", 2);//he
	string s5(10, 'a');//aaaaaaaaaa

	char str1[] = "china";
	char str2[] = "�й�";
}

void testIterator() {
	string s2("hello world");
	/*
	   ��������һ���������ݵķ��ʻ���
	   ʹ�÷�ʽ��������ָ���ʹ�÷�ʽ
	   begin��������ָ�������ĵ�һ��Ԫ�ص�λ��
	   end��������ָ�����������һ��Ԫ�ص���һ��λ��
	   ����ҿ���[begin, end]
	*/
	string::iterator it = s2.begin();
	while (it != s2.end()) {
		//*it = 'a';  �ɶ���д
		cout << *it << " " ;
		++it;
	}
	cout << endl;

	//���������
	// begin��������ָ�������ĵ�һ��Ԫ�ص�ǰһ��λ��
	//end��������ָ�����������һ��Ԫ�ص�λ��
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	for (unsigned int i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	//��Χfor
	for (auto& ch : s2) {//�������͵Ĳſ�д����������ֻ�ɶ�
		ch = '1';
	}
	cout << s2 << endl;

	//const������ֻ��
	const string s3("hello");
	string::const_iterator s3it = s3.begin();
	while (s3it != s3.end())
	{
		//*s3it = 'a';
		cout << *s3it << " ";
		++s3it;
	}
	cout << endl;

	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	list<int>::iterator lit = l.begin();
	while (lit != l.end()) {
		cout << *lit << " " ;
		++lit;
	}
	cout << endl;
}

void testCap() {
	//reserve��ֻ���������������������������ı�����
	//				  �������ݴ��������Ч��
	//string�����߼�����ʼ��С15,�ڶ���������ʣ��1.5��

	string s("123");
	cout << s.size() << endl;//3
	cout << s.length() << endl;//3
	//cout << s.max_size() << endl;
	cout << s.capacity() << endl;//15

	s.resize(10);//�ı�size�����ı�����
	cout << s.size() << endl;//10
	cout << s.capacity() << endl;//15
	//�������������ˣ���size���
	cout << s << "end" << endl;//123       end
	s.resize(10,'1');
	cout << s << "end" << endl;//123111111

	s.resize(1);
	cout << s << "end" << endl;//1end

	s.resize(20);
	cout << s.size() << endl;//20
	cout << s.capacity() << endl;//31
	cout << s << "end" << endl;//1                   end

	char str[] = "12345\0\0\0\0\0";
	cout << str << "end" << endl;//12345end

	//reserve��ֻ���������������������������ı�����
	//��resize��ȣ���ֱ�Ӹ���������û�����������Ĺ��̣���ǿ��Ч��
	s.reserve(50);//���ı�size�ı�����
	cout<< "s.reserve(50);" <<endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string s2;
	int cap = s2.capacity();
	//s2.reserve(100);
	cout << cap << endl;
	for (int i = 0; i < 100; i++) {
		s2.push_back(i);//push_backֻ�ܲ��뵥���ַ�
		if (cap != s2.capacity()) {
			cap = s2.capacity();
			cout << cap << endl;
		}
	}

	s2.shrink_to_fit();
	cout << "s2.shrink_to_fit();" << endl;
	cout << s2.capacity() << endl;

	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	//clearֻ������ݣ�size���0��
	//		   ���ͷ��ڴ棬capacity����
	s2.clear();
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	//shrink_to_fit �����жϣ�size��capacity����һ����ʱ�򲻼�������
	//														     ������һ���ͼ��ٵ�size����ʵ�����
	s2.shrink_to_fit();
	cout << "s2.shrink_to_fit();" << endl;
	cout << s2.capacity() << endl;
}

void testAcc() {
	string s("123456");
	cout << s[2] << endl;
	cout << s.at(2) << endl;
}

void testModl() {
//	string s;
//	s.append("012");
//	cout << s << endl;
//	string s2("345");
//	s.append(s2);
//	cout << s << endl;
//	string s3("1234567");
//	s.append(s3, 5, 2);
//	//������Ȼ����һ��������
//	char str[] = { "8910" };
//	s.append(str, str + sizeof(str) / sizeof(str[0]));//������ 
////   append(str��һ��Ԫ�ص�λ��, str���һ��Ԫ�ص���һ��λ��)
//	cout << s << endl;

	////insert(pos, string)����posǰ������µ��ַ���
	//string s("123");
	//cout << s << endl;
	//s.insert(0, "0");
	//cout << s << endl;
	//s.insert(0, "-1-2");
	//cout << s << endl;
	//string s2("456");
	//s.insert(8, s2);
	//cout << s << endl;
	//s.insert(s.begin() + 4, '+');//������ֻ�ܲ����ַ�
	//cout << s << endl;
	//char str[] = { "78910" };
	////	s.append(str, str + sizeof(str) / sizeof(str[0]));
	//s.insert(s.end(), str, str + sizeof(str) / sizeof(str[0]));
	//cout << s << endl;

	//string s("123");
	//cout << s << endl;
	//string s2("45");
	////s.assign(s2);
	//s = s2;
	//cout << s << endl;

	//string s;
	//s += '0';
	//cout << s << endl;
	//s += "123";
	//cout << s << endl;
	//s += string("string");//string �������ں̣ܶ�ֻ�����ڱ���
	//cout << s << endl;

	//s.erase(0, 2);//ɾ����ǰ����Ԫ��
	//cout << s << endl;
	//s.erase(s.begin());//ɾ���˵�һ��Ԫ��
	//cout << s << endl;
	//s.erase(s.begin() + 1, s.end() - 1);//����һ�������һ�����ⶼɾ����
	//cout << s << endl;

	string s("01234");
	//cout << s << endl;
	//string s2("56789");
	//s.replace(3, 1, s2);//��s2�滻s�ӵ�3��λ�ÿ�ʼ��һ���ַ���"012567894"
	//cout << s << endl;
	//swap(s, s2);

	//string s1("123");
	//string s2("45");
	//cout << (s1 < s2) << endl;

	string s1;
	string s2;
	cin >> s1;//�����ո��ȡ����
	getline(cin, s2);//Ĭ���������ж�ȡ����
	cout << s1 << endl;
	cout << s2 << endl;
}

/*���ýӿ�
���죬�������ַ�����ʼ��
��������
begin end
������size, resize, reserve
Ԫ�ط��ʣ�operator[]
�޸ģ�operator+=, pop_back, swap(��Ա������)
����������c_str, find, substr, <, >, <=, ==, !=, >>, <<, getline
*/

int main() {
	//testString1();
	testModl();
	getchar();
	return 0;
}

