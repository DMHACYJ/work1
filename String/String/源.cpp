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
	char str2[] = "中国";
}

void testIterator() {
	string s2("hello world");
	/*
	   迭代器：一种容器内容的访问机制
	   使用方式：类似于指针的使用方式
	   begin迭代器：指向容器的第一个元素的位置
	   end迭代器：指向容器的最后一个元素的下一个位置
	   左闭右开：[begin, end]
	*/
	string::iterator it = s2.begin();
	while (it != s2.end()) {
		//*it = 'a';  可读可写
		cout << *it << " " ;
		++it;
	}
	cout << endl;

	//反向迭代器
	// begin迭代器：指向容器的第一个元素的前一个位置
	//end迭代器：指向容器的最后一个元素的位置
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

	//范围for
	for (auto& ch : s2) {//引用类型的才可写，不加引用只可读
		ch = '1';
	}
	cout << s2 << endl;

	//const迭代器只读
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
	//reserve：只增加容量，不会减少容量，不会改变容量
	//				  减少增容次数，提高效率
	//string增容逻辑：初始大小15,第二次两倍，剩余1.5倍

	string s("123");
	cout << s.size() << endl;//3
	cout << s.length() << endl;//3
	//cout << s.max_size() << endl;
	cout << s.capacity() << endl;//15

	s.resize(10);//改变size，不改变容量
	cout << s.size() << endl;//10
	cout << s.capacity() << endl;//15
	//输出运算符重载了，按size输出
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

	//reserve：只增加容量，不会减少容量，不会改变容量
	//跟resize相比，是直接给的容量，没有增加容量的过程，增强了效率
	s.reserve(50);//不改变size改变容量
	cout<< "s.reserve(50);" <<endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string s2;
	int cap = s2.capacity();
	//s2.reserve(100);
	cout << cap << endl;
	for (int i = 0; i < 100; i++) {
		s2.push_back(i);//push_back只能差入单个字符
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
	//clear只清空内容，size变成0，
	//		   不释放内存，capacity不变
	s2.clear();
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	//shrink_to_fit 内置判断：size和capacity量级一样的时候不减少容量
	//														     量级不一样就减少到size最合适的量级
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
//	//数组天然的是一个迭代器
//	char str[] = { "8910" };
//	s.append(str, str + sizeof(str) / sizeof(str[0]));//迭代器 
////   append(str第一个元素的位置, str最后一个元素的下一个位置)
//	cout << s << endl;

	////insert(pos, string)：在pos前面插入新的字符串
	//string s("123");
	//cout << s << endl;
	//s.insert(0, "0");
	//cout << s << endl;
	//s.insert(0, "-1-2");
	//cout << s << endl;
	//string s2("456");
	//s.insert(8, s2);
	//cout << s << endl;
	//s.insert(s.begin() + 4, '+');//迭代器只能插入字符
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
	//s += string("string");//string 生命周期很短，只存在于本行
	//cout << s << endl;

	//s.erase(0, 2);//删除了前两个元素
	//cout << s << endl;
	//s.erase(s.begin());//删除了第一个元素
	//cout << s << endl;
	//s.erase(s.begin() + 1, s.end() - 1);//除第一个和最后一个以外都删除了
	//cout << s << endl;

	string s("01234");
	//cout << s << endl;
	//string s2("56789");
	//s.replace(3, 1, s2);//用s2替换s从第3个位置开始的一个字符："012567894"
	//cout << s << endl;
	//swap(s, s2);

	//string s1("123");
	//string s2("45");
	//cout << (s1 < s2) << endl;

	string s1;
	string s2;
	cin >> s1;//遇到空格读取结束
	getline(cin, s2);//默认遇到换行读取结束
	cout << s1 << endl;
	cout << s2 << endl;
}

/*常用接口
构造，拷贝，字符串初始化
迭代器：
begin end
容量：size, resize, reserve
元素访问：operator[]
修改：operator+=, pop_back, swap(成员函数的)
其它操作：c_str, find, substr, <, >, <=, ==, !=, >>, <<, getline
*/

int main() {
	//testString1();
	testModl();
	getchar();
	return 0;
}

