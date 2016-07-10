#define _CRT_SECURE_NO_WARNINGS 1

#include "Calendar.h"
#include "week.h"
#include <iomanip>

//菜单函数 
void manu()
{
	cout << "*********************************************************" << endl;
	cout << "************Welcome to Perpetual Calendar****************" << endl;
	cout << "*********************************************************" << endl;
	cout << "**********1、加上到指定日期的天数************************" << endl;
	cout << "**********2、减去到指定日期的天数************************" << endl;
	cout << "**********3、计算两个日期相差天数************************" << endl;
	cout << "**********4、日历打印************************************" << endl;
	cout << "**********0、退出日历************************************" << endl;
	cout << "*********************************************************" << endl;
}
//加上到指定日期的天数
void calc_add()
{
	Date c1;
	Date c2;
	int day = 0;
	cout << "请输入指定日期:" << endl;
	cin >> c1;
	cout << "请输入要加上的天数" << endl;
	cin >> day;
	c2 = c1 + day;
	cout << c2 << endl;
}
//减去到指定日期的天数
void calc_del()
{
	Date c1;
	Date c2;
	int day = 0;
	cout << "请输入指定日期:" << endl;
	cin >> c1;
	cout << "请输入要减去的天数" << endl;
	cin >> day;
	c2 = c1 - day;
	cout << c2 << endl;
}
//计算两个日期相差天数
void calc_differ()
{
	Date c1;
	Date c2;
	int day = 0;
	cout << "请输入第一个日期:" << endl;
	cin >> c1;
	cout << "请输入第二个日期" << endl;
	cin >> c2;
	day = c1 - c2;
	cout << "两日期相差" << day << "天" << endl;
}
//日历打印
void calc_Print()
{
	cout << "请输入日期<年、月>" << endl;
	int year = 0;
	int month = 0;
	cout << "the year is ->";
	cin >> year;
	cout << "the month is ->:";
	cin >> month;
	Date c1(year,month, 1);
	cout << "**********************"<<year<<"年"<<month<<"月"<<"**********************" << endl;
	cout << "Sun" << "  |  " << "Mon" << "  |  " << "Tue" << "  |  " << "Wed" << "  |  " << "Thu" << "  |  " << "Fri" << "  |  " << "Sat" << "  |  " << endl;
	cout << "____________________________________________________" << endl;
	int w = the_week(year, month, 1);//本月1号星期数
	int n = c1.num_of_day();//本月天数
	if (w == 7)
	{
		w = 0;
	}
	int j = 0;
	while (w > 0)
	{
		cout << "     |  ";
		w--;
		j++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i < 10)
		{
			cout << setiosflags(ios::left) << setw(3);
			cout << " " << i << "  | ";
		}
		else
		{
			cout << setiosflags(ios::left) << setw(2);
			cout << " " << i << "  | ";
		}
		j++;
		if (j % 7 == 0)
		{
			cout << endl<<"____________________________________________________" << endl;
		}
	}
	cout << endl << "*****************************************************" << endl;
}
