#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void print_manu()
{
	printf("*************************************************\n");
	printf("*****************欢迎使用电话本******************\n");
	printf("****请输入操作选项:>*****************************\n");
	printf("***********1、ADD        2、DEL******************\n");
	printf("***********3、SEARCH     4、MODIFY***************\n");
	printf("***********5、SHOW       6、CLEAR****************\n");
	printf("***********7、SORT       0、EXIT*****************\n");
	printf("*************************************************\n");
}

void init_contact(Pcon pcon)
{
	pcon->size = 0;
	pcon->capacity = INIT_NUM;
	Per* tmp = (Per*)malloc(sizeof(Per)*INIT_NUM);
	if (tmp == NULL)
	{
		printf("out of memory!\n");
		return;
	}
	pcon->con = tmp;
	memset(pcon->con,0,sizeof(Per)*INIT_NUM);	
	load_contact(pcon);
}

void cheak(Pcon pcon)
{
	assert(pcon);
	if (pcon->size == pcon->capacity)
	{
		pcon->capacity += ADD_NUM;
		pcon->con = (Per*)realloc(pcon->con, sizeof(Per)*pcon->capacity);
	}
}

void add_contact(Pcon pcon)
{
	assert(pcon);
	cheak(pcon);
	printf("请输入姓名:>");
	scanf("%s", pcon->con[pcon->size].name);
	printf("请输入性别:>");
	scanf("%s", pcon->con[pcon->size].sex);
	printf("请输入年龄:>");
	scanf("%d", &pcon->con[pcon->size].age);
	printf("请输入电话:>");
	scanf("%s", pcon->con[pcon->size].tele);
	printf("请输入住址:>");
	scanf("%s", pcon->con[pcon->size].addr);
	pcon->size++;
	printf("插入成功\n");
}
//由于删除和查找有公共部分代码，所以封装新函数
static int  fint_all(Pcon pcon,char* find_name)
{
	assert(pcon);
	assert(find_name);
	size_t i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(find_name, pcon->con[i].name) == 0)
			return i;
	}
	return -1;
}

void del_contact(Pcon pcon)
{
	//char* tmp = NULL;//报错
	char find_name[MAX_NAME];
	size_t index = 0;
	assert(pcon);
	if (pcon->size == 0)
	{
		printf("电话本为空，无法删除\n");
		return;
	}
	printf("请输入要删除联系人的姓名:>");
	scanf("%s", find_name);
	index = fint_all(pcon,find_name);
	if (index == -1)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		for (; index < pcon->size - 1; ++index)
		{
			pcon->con[index] = pcon->con[index + 1];
		}
		--pcon->size;
		printf("删除成功\n");
	}
}

void search_contact(Pcon pcon)
{
	char find_name[MAX_NAME] = {0};
	int index = 0;
	assert(pcon);
	if (pcon->size == 0)
	{
		printf("电话本为空\n");
		return;
	}
	printf("请输入想查找人的姓名:>");
	scanf("%s", find_name);
	index = fint_all(pcon, find_name);
	if (index == -1)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("----------信息如下----------\n");
		printf("%10s,%5s,%5d,%10s,%10s\n","NAME","SEX","AGE","TELE","ADR");
		printf("%10s %5s %5d %10s %10s\n",
			pcon->con[index].name,
			pcon->con[index].sex,
			pcon->con[index].age,
			pcon->con[index].tele,
			pcon->con[index].addr);
	}
}

void modify_contact(Pcon pcon)
{
	char find_name[MAX_NAME] = {0};
	int index = 0;
	assert(pcon);
	printf("请输入想修改人的姓名:>");
	scanf("%s",find_name);
	index = fint_all(pcon,find_name);
	if (index == -1)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("------请输入修改联系人的信息------\n");
		printf("请重新输入姓名:>");
		scanf("%s", pcon->con[index].name);
		printf("请重新输入性别:>");
		scanf("%s", pcon->con[index].sex);
		printf("请重新输入年龄:>");
		scanf("%d", &pcon->con[index].age);
		printf("请重新输入电话:>");
		scanf("%s", pcon->con[index].tele);
		printf("请重新输入住址:>");
		scanf("%s", pcon->con[index].addr);
	}
	printf("修改成功\n");
}

void clear_contat(Pcon pcon)
{
	assert(pcon);
	pcon->size = 0;
}

static void Swap(Per* p1,Per*p2)
{
	Per tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void sort_contact(Pcon pcon)
{
	size_t i = 0;
	size_t j = 0;
	int flag = 1;
	assert(pcon);
	for (i = 0; i < pcon->size - 1; ++i)
	{
		flag = 1;
		for (j = 0; j < pcon->size - i - 1; ++j)
		{
			if (strcmp(pcon->con[j].name, pcon->con[j + 1].name)>0)
			{
				Swap(&pcon->con[j], &pcon->con[j+1]);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	printf("排序成功\n");
}

void show_contact(Pcon con)
{
	size_t i = 0;
	if (con->size == 0)
	{
		printf("the contact is empty\n");
		system("pause");
		return;
	}
	printf("-----------------my_con-----------------\n");
	printf("%10s\t%5s\t%5s\t%10s\t%10s\n", "NAME", "SEX", "AGE", "TELE", "ADDR");
	for (i = 0; i < con->size; i++)
	{
		printf("%10s\t%5s\t%5d\t%10s\t%10s\n",\
			con->con[i].name,\
			con->con[i].sex,\
			con->con[i].age,\
			con->con[i].tele,\
			con->con[i].addr);
	}
}

void save_contact(Pcon pcon)
{
	assert(pcon);
	FILE *pfWrite = fopen("text.dat","w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	size_t i = 0;
	//while (fwrite(&(pcon->con[i]), sizeof(Per), 1, pfWrite))
	//{
	//	++i;
	//}
	for (; i < pcon->size; ++i)
	{
		fwrite(&(pcon->con[i]), sizeof(Per), 1, pfWrite);
	}
	fclose(pfWrite);
}

void load_contact(Pcon pcon)
{
	assert(pcon);
	FILE *pfRead = fopen("text.dat", "r");
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	Per tmp = {0};
	int i = 0;
	while (fread(&tmp, sizeof(Per), 1, pfRead))
	{
		cheak(pcon);
		pcon->con[i] = tmp;
		pcon->size++;
		i++;
	}
	//for (i = 0; fread(&tmp, sizeof(Per), 1, pfRead); ++i)
	//{
	//	//fread(&tmp, sizeof(Per), 1, pfRead);
	//	cheak(pcon);
	//	pcon->con[i] = tmp;
	//	pcon->size++;
	//}
	fclose(pfRead);
}
