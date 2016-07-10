#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>

using namespace std;

enum Week
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class Date
{
	friend ostream& operator<<(ostream &out, Date &d);
	friend istream& operator>>(istream &c_in, Date &d);
public:
	Date(int year = 1990, int month = 1, int day = 1, int week = Monday);
	Date(Date &d);
	Date& operator= (Date &d);

public:
	bool operator<(Date &d);
	bool operator == (Date& c);
	bool operator>(Date& c);
	bool operator>=(Date& c);
	bool operator<=(Date& c);

public:
	Date operator+(int day);
	Date operator -(int day);
	int operator-(Date& c);
	bool is_leap();
	int num_of_day();

private:
	int _year;
	int _month;
	int _day;
	int _week;
};

#endif//__DATE_H__