#define _CRT_SECURE_NO_WARNINGS 1

#include "Calendar.h"
#include "week.h"
#include <iomanip>

//�˵����� 
void manu()
{
	cout << "*********************************************************" << endl;
	cout << "************Welcome to Perpetual Calendar****************" << endl;
	cout << "*********************************************************" << endl;
	cout << "**********1�����ϵ�ָ�����ڵ�����************************" << endl;
	cout << "**********2����ȥ��ָ�����ڵ�����************************" << endl;
	cout << "**********3���������������������************************" << endl;
	cout << "**********4��������ӡ************************************" << endl;
	cout << "**********0���˳�����************************************" << endl;
	cout << "*********************************************************" << endl;
}
//���ϵ�ָ�����ڵ�����
void calc_add()
{
	Date c1;
	Date c2;
	int day = 0;
	cout << "������ָ������:" << endl;
	cin >> c1;
	cout << "������Ҫ���ϵ�����" << endl;
	cin >> day;
	c2 = c1 + day;
	cout << c2 << endl;
}
//��ȥ��ָ�����ڵ�����
void calc_del()
{
	Date c1;
	Date c2;
	int day = 0;
	cout << "������ָ������:" << endl;
	cin >> c1;
	cout << "������Ҫ��ȥ������" << endl;
	cin >> day;
	c2 = c1 - day;
	cout << c2 << endl;
}
//�������������������
void calc_differ()
{
	Date c1;
	Date c2;
	int day = 0;
	cout << "�������һ������:" << endl;
	cin >> c1;
	cout << "������ڶ�������" << endl;
	cin >> c2;
	day = c1 - c2;
	cout << "���������" << day << "��" << endl;
}
//������ӡ
void calc_Print()
{
	cout << "����������<�ꡢ��>" << endl;
	int year = 0;
	int month = 0;
	cout << "the year is ->";
	cin >> year;
	cout << "the month is ->:";
	cin >> month;
	Date c1(year,month, 1);
	cout << "**********************"<<year<<"��"<<month<<"��"<<"**********************" << endl;
	cout << "Sun" << "  |  " << "Mon" << "  |  " << "Tue" << "  |  " << "Wed" << "  |  " << "Thu" << "  |  " << "Fri" << "  |  " << "Sat" << "  |  " << endl;
	cout << "____________________________________________________" << endl;
	int w = the_week(year, month, 1);//����1��������
	int n = c1.num_of_day();//��������
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
