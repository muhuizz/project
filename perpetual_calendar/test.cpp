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
		cout << "������ѡ��" << endl;
		cin >> input;
		switch (input)
		{
			//1�����ϵ�ָ�����ڵ�����
		case 1:
			calc_add();
			break;
			//2����ȥ��ָ�����ڵ�����
		case 2:
				calc_del();
			break;
			//3���������������������
		case 3:
				calc_differ();
			break;
			//4��������ӡ
		case 4:
				calc_Print();
			break;
		case 0:
			cout << "Thanks" << endl;
			system("pause");
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << "�����������������" << endl;
			input = 1;
			break;
		}
		cout << "���»س�����" << endl;
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

