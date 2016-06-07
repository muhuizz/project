#define _CRT_SECURE_NO_WARNINGS 1


#include"contact.h"

void Test()
{
	int input = 1;
	Con my_con;
	init_contact(&my_con);
	while (input)
	{
		print_manu();
		printf("请输入操作选项:>");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			add_contact(&my_con);
			break;
		case DEL:
			del_contact(&my_con);
			break;
		case SEARCH:
			search_contact(&my_con);
			break;
		case MODIFY:
			modify_contact(&my_con);
			break;
		case SHOW:
			show_contact(&my_con);
			break;
		case CLEAR:
			clear_contat(&my_con);
			break;
		case SORT:
			sort_contact(&my_con);
			break;
		case EXIT:
			save_contact(&my_con);
			system("pause");
			exit(EXIT_SUCCESS);
			break;
		default:
			save_contact(&my_con);
			printf("输入有误，请重新输入\n");
		}
	}
}

int main()
{
	Test();
	system("pause");
	return 0;
}