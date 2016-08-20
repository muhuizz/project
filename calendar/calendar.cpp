#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<cstdlib>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out,const Date& d);
public:
	Date(int year = 1900,int month = 1,int day =1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if ((_year < 1) || (_month > 12) || (_month < 1) || (_day > day_of_month(_year,_month)) || (_day < 1))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
public:
	Date operator+(int num)
	{
		Date tmp(*this);
		tmp._day += num;
		if ((tmp._day <= 0) || (tmp._day > day_of_month(tmp._year, tmp._month)))
		{
			adjust_date(tmp);
		}
		return tmp;
	}
	Date operator-(int num)
	{
		Date tmp(*this);
		tmp._day -= num;
		if ((tmp._day <= 0) || (tmp._day > day_of_month(tmp._year, tmp._month)))
		{
			adjust_date(tmp);
		}
		return tmp;
	}
	int operator-(const Date& d)
	{
		Date max_date = (*this) > d ? (*this) : d;
		Date min_date = (*this) < d ? (*this) : d;
		int count = 0;
		while (max_date > min_date)
		{
			count++;
			min_date = min_date + 1;
		}
		return count;
	}

	bool operator>(const Date& d)
	{
		if ((_year > d._year) || ((_year == d._year) && (_month > d._month)) || ((_year == d._year) && (_month == d._month) && (_day > d._day)))
		{
			return true;
		}
		return false;
	}
	bool operator==(const Date& d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		{
			return true;
		}
		return false;
	}
	bool operator<(const Date& d)
	{
		return !((*this > d) || (*this == d));
	}
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}

private:
	int day_of_month(int year,int month)
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int count = 0;
		if ((month == 2) && isleap(year))
		{
			count = 1;
		}
		return count + arr[month];
	}
	int isleap(int year)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			return 1;
		}
		else
			return 0;
	}
	void adjust_date(Date& tmp)
	{
		if (tmp._day <= 0)
		{
			while (tmp._day <= 0)
			{
				tmp._month--;
				if (tmp._month == 0)
				{
					tmp._year--;
					tmp._month = 12;
				}
				tmp._day += (day_of_month(tmp._year,tmp._month));
			}
		}
		else
		{
			while (tmp._day > day_of_month(tmp._year, tmp._month))
			{
				tmp._day -= day_of_month(tmp._year, tmp._month);
				tmp._month++;
				if (tmp._month == 13)
				{
					tmp._month = 1;
					tmp._year++;
				}
			}
		}
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "Äê" << d._month << "ÔÂ" << d._day << "ÈÕ";
	return out;
}

void test()
{
	Date d1(2016,8,20);
	Date d2(1996.8, 9);
	cout << (d1 - d2) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}