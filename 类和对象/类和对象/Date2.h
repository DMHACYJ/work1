#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1) 
//		: _year(year)
	//	, _month(month)
		//, _day(day)
	{
		//判断日期的正确性
		if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 30) {
			_year = 1;
			_month = 1;
			_day = 1;
			cout << "日期非法，重置为默认值：1 - 1 - 1" << endl;
		}
		else {
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
	}

	int getDay(int year, int month) {
		static int days[] = { 31,28 ,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month - 1];
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ++day;
		}
		return day;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date& operator = (const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return*this;
	}
	Date operator+(int days) {
		Date tmp(*this);
		tmp += days;
		return tmp;
	}
	Date operator-(int days) {
		Date tmp(*this);
		tmp -= days;
		return tmp;
	}
	Date &operator+=(int days) {
		if (days < 0) {
			return *this -= (-days);
		}
		_day += days;
		while (_day > getDay(_year, _month)) {
			_day -= getDay(_year, _month);
			++_month;
			if (_month == 13) {
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date& operator-=(int days) {
		_day -= days;
		while (_day <= 0) {
			--_month;
			if (_month == 0) {
				_month = 12;
				_year--;
			}	
			_day += getDay(_year, _month);
		}
		return *this;
	}
	Date &operator--() {//前置--
		return *this -= 1;
	}
	Date operator--(int) {//后置--
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}
	Date& operator++() {//前置++
		return *this += 1;
	}
	Date operator++(int) {//后置++
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	bool operator>(const Date& d)const {
		if (_year > d._year) return true;
		if (_year == d._year) {
			if (_month > d._month) return true;
			else if (_month == d._month)  if (_day > d._day) return true;
		}
		return false;
	}
	bool operator>=(const Date& d)const {
		return !(*this < d);
	}
	bool operator<(const Date& d)const {
		if (_year < d._year) return true;
		if (_year == d._year) {
			if (_month < d._month) return true;
			else if (_month == d._month)  if (_day < d._day) return true;
		}
		return false;
	}
	bool operator<=(const Date& d)const {
		return !(*this > d);
	}
	bool operator==(const Date& d)const {
		if (_year == d._year && _month == d._month && _day == d._day) return true;
		else return false;
	}
	bool operator!=(const Date& d)const {
		return !(*this == d);
	}
private:
	int _year;
	int _month;
	int _day;
};