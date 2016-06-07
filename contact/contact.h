#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#define MAX_PEO 1000
#define INIT_NUM 2
#define ADD_NUM 2

enum
{
	EXIT = 0,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
};

typedef struct Person
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Per;

typedef struct Contact
{
	Per* con;
	size_t size;	 //当前通讯录人数
	size_t capacity;//此时通讯录容量
}Con,*Pcon;

void print_manu();
void init_contact(Pcon pcon);
void add_contact(Pcon pcon);
void del_contact(Pcon pcon);
void search_contact(Pcon pcon);
void modify_contact(Pcon pcon);//修改
void clear_contat(Pcon pcon);
void sort_contact(Pcon pcon);
void show_contact(Pcon con);
void save_contact(Pcon pcon);
void load_contact(Pcon pcon);

#endif