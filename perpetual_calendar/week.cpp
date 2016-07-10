#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int is_leap(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		return 1;
	}
	return 0;
}

int num_of_month(int flag, int month)
{
	switch (month)
	{
	case 1:
		if (flag == 1)
			return 5;
		else
			return 6;
		break;
	case 2:
		if (flag == 1)
			return 1;
		else
			return 2;
	case 3:
	case 11:
		return 2;
	case 4:
	case 7:
		return 5;
	case 5:
		return 0;
	case 6:
		return 3;
	case 8:
		return 1;
	case 9:
	case 12:
		return 4;
	case 10:
		return 6;
	}
	return -1;
}

int the_week(int year, int month, int day)
{
	int week = 0;
	int tmp = 0;
	int tmp1 = 0;//年份代码 
	int tmp2 = 0;

	tmp1 = year % 100;
	tmp = (int)(tmp1 / 4) + tmp1;
	tmp1 = tmp % 7;
	if (tmp1 == 0)
	{
		tmp1 = 7;
	}
	tmp2 = num_of_month(is_leap(year), month);

	week = (tmp1 + tmp2 + day) % 7;
	if (year < 2000)
		week++;
	if (week == 0)
		week = 7;
//	cout <<"今天星期"<< week << endl;
	return week;
}
