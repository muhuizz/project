#define _CRT_SECURE_NO_WARNINGS 1

#include "convert.h"
#include <Windows.h>

int main()
{
	FILE *pfRead = NULL;
	FILE *pfWrite = NULL;

	pfRead = fopen(INPUT_FILE, "r");
	if (NULL == pfRead)
	{
		perror("open file for read");
		system("pause");
		exit(EXIT_FAILURE);
	}
	pfWrite = fopen(OUTPUT_FILE, "w");
	if (NULL == pfWrite)
	{
		fclose(pfRead);
		perror("open file for Write");
		system("pause");
		exit(EXIT_FAILURE);
	}

	printf("注释转化开始...\n");
	comment_convert(pfRead, pfWrite);
	//Sleep(2000);
	printf("注释转化结束\n");
	system("pause");
	return 0;
}