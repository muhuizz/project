#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdlib>
#include  <conio.h>
#include "Date.h"
#include "Calendar.h"

void Test()
{
	int input = 1;
	while (input)
	{
		manu();
		cout << "请输入选项" << endl;
		cin >> input;
		switch (input)
		{
			//1、加上到指定日期的天数
		case 1:
			calc_add();
			break;
			//2、减去到指定日期的天数
		case 2:
				calc_del();
			break;
			//3、计算两个日期相差天数
		case 3:
				calc_differ();
			break;
			//4、日历打印
		case 4:
				calc_Print();
			break;
		case 0:
			cout << "Thanks" << endl;
			system("pause");
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			input = 1;
			break;
		}
		cout << "按下回车继续" << endl;
		system("pause");
		system("cls");
	}
}
int main()
{
	Test();
	system("pause");
	return 0;
}

