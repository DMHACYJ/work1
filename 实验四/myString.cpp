#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;
class MyString
{
public:
	//¹¹Ôì
	MyString(char* str = "") {
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}

	MyString(const MyString& str)
		:_str(NULL)
		, _size(0)
		, _capacity(0)
	{
		MyString tmp(str._str);
		Swap(tmp);
	}
    void Swap(MyString& str) {
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	MyString& operator=(MyString str) {
		Swap(str);
		return *this;
	}
	
	const char* c_str() const {
		return _str;
	}

	~MyString() {
		if (_str) {
			delete[] _str;
			_str = NULL;
			_size = _capacity = 0;
		}
	}
	void reserve(size_t n) {
		if (n > _capacity) {
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	MyString& operator+(const MyString&  str) {
		insert(_size, str._str);
		return *this;
	}

	void insert(size_t pos, const char* str) {
		assert(pos <= _size);
		int sz = strlen(str);
		if (_size + sz > _capacity)
			reserve(_size + sz);
		size_t end = _size + sz;
		while (end > pos + sz - 1) {
			_str[end] = _str[end - sz];
			--end;
		}
		int i = 0;
		while (*str) {
			_str[pos + i] = *str++;
			++i;
		}
		_size += sz;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void test() {
	MyString a("Hello");
	MyString b("World");
	MyString c;
	c = a + b;
	cout << c.c_str() << endl;
}
int main() {
	test();
	return 0;
}
