#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"
#include "week.h"

//默认函数
/*
	多文件定义类时，缺省参数只能在声明出给出
*/
Date::Date(int year, int month, int day, int week)
		:_year(year)
		, _month(month)
		, _day(day)
		, _week(week)
{
	if ((_year != 1990) || (_month != 1) || (_day != 1))
	{
		_week = the_week(_year,_month,_day);
	}
}
Date::Date(Date &c)
{
	_year = c._year;
	_month = c._month;
	_day = c._day;
	_week = c._week;
}
Date& Date::operator= (Date &c)
{
	_year = c._year;
	_month = c._month;
	_day = c._day;
	_week = c._week;
	return *this;
}

//输出运算符重载
ostream& operator<<(ostream &out, Date &c)
{
	out << c._year << "年 " << c._month << "月 " << c._day << "日" << "\t星期" << c._week;
	return out;
}
//输入运算符重载
istream& operator>>(istream &c_in, Date &c)
{
	c_in >> c._year >> c._month >> c._day;
	c._week = the_week(c._year, c._month, c._day);
	return c_in;
}

//日期比较
bool Date::operator<(Date &c)
{
	if ((c._year > _year)
		|| ((c._year == _year) && (c._month > _month)) ||
		((c._year == _year) && (c._month == _month) && (c._day > _day)))
	{
		return true;
	}
	return false;
}
bool Date::operator == (Date& c)
{
	if ((c._year == _month) && (c._month == _month) && (c._day == _day))
	{
		return true;
	}
	return false;
}
bool Date::operator>(Date& c)
{
	return !((*this <c) || (*this == c));
}
bool Date::operator >= (Date& c)
{
	return (*this > c) || (*this == c);
}
bool Date::operator <= (Date& c)
{
	return (*this < c) || (*this == c);
}


///日期类计算重载

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp._week += day;
	int x = 0;
	while (day > 0)
	{
		x = tmp.num_of_day();
		if (x - tmp._day >= day)
		{
			tmp._day += day;
			break;
		}
		else
		{
			day = day - (x - tmp._day);
			tmp._month++;
			tmp._day = 0;
		}
		if (tmp._month > 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}
	tmp._week %= 7;
	if (tmp._week == 0)
	{
		tmp._week = 7;
	}
	return tmp;
}

Date Date::operator -(int day)
{
	Date tmp(*this);
	int x = 0;
	tmp._week = tmp._week - day;
	while (day > 0)
	{
		if (tmp._day > day)
		{
			tmp._day -= day;
			day = 0;
		}
		else
		{
			day = day - tmp._day;
			tmp._day = 0;
		}
		if (tmp._day == 0)
		{
			tmp._month--;
			if (tmp._month < 1)
			{
				tmp._year--;
				tmp._month = 12;
			}
			tmp._day = tmp.num_of_day();
		}
	}

	tmp._week %= 7;
	if (tmp._week < 0)
	{
		tmp._week += 7;
	}
	if (tmp._week == 0)
		tmp._week = 7;
	return tmp;
}

int Date::operator-(Date& c)
{
	/*同一天*/
	if (*this == c)
	{
		return 0;
	}
	/*(*this) > d*/
	int count = 0;
	if (*this > c)
	{
		Date tmp(*this);

		//日数相差的day数
		count = tmp._day - c._day;

		//月份相差的day数
		int flag = 1;
		if (tmp._month < c._month)
		{
			flag = -1;
			int x = tmp._month;
			tmp._month = c._month;
			c._month = x;
		}
		while (tmp._month > c._month)
		{
			tmp._month--;
			count += (tmp.num_of_day()*flag);
		}

		//年份相差的day数
		while (tmp._year > c._year)
		{
			tmp._year--;
			if (tmp.is_leap())
				count = count + 366;
			else
				count = count + 365;
		}
		return count;
	}
	/*(*this) < d*/
	else
	{
		return -(c - *this);
	}
}

bool Date::is_leap()
{
	if ((this->_year % 400 == 0) || ((this->_year % 4 == 0) && (this->_year % 100 != 0)))
		return true;
	return false;
}

int Date::num_of_day()
{
	if ((this->_month == 1) || (this->_month == 3) || (this->_month == 5) || (this->_month == 7) || (this->_month == 8) || (this->_month == 10) || (this->_month == 12))
		return 31;
	else if ((this->_month == 4) || (this->_month == 6) || (this->_month == 9) || (this->_month == 11))
		return 30;
	else
	{
		if (this->is_leap())
		{
			return 29;
		}
		return 28;
	}
}

