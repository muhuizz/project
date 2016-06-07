#define _CRT_SECURE_NO_WARNINGS 1

#include "convert.h"

enum STATE state = NULL_STATE;

void Do_Null_State(FILE * pfRead, FILE * pfWrite)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '/':
		second = fgetc(pfRead);
		if ('*' == second)
		{
			fputc('/', pfWrite);
			fputc('/', pfWrite);
			state = C_STATE;
		}
		else if ('/' == second)
		{
			fputc(first, pfWrite);
			fputc(second, pfWrite);
			state = CPP_STATE;
		}
		else
		{
			fputc(first, pfWrite);
			fputc(second, pfWrite);
		}
		break;
	case EOF:
		fputc(first, pfWrite);
		state = END_STATE;
		break;
	case '"':
		fputc(first, pfWrite);
		state = STR_STATE;
		break;
	default:
		fputc(first, pfWrite);
		break;
	}

}

void Do_C_State(FILE * pfRead, FILE * pfWrite)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '*':
		second = fgetc(pfRead);
		if ('/' == second)
		{
			third = fgetc(pfRead);
			if (third == '\n')
			{
				fputc(third, pfWrite);
				state = NULL_STATE;
			}
			else if ('/' == third)
			{
				state = NULL_STATE;
				fputc('\n', pfWrite);
				ungetc(third, pfRead);
			}
			else
			{
				fputc('\n', pfWrite);
				fputc(third, pfWrite);
				state = NULL_STATE;
			}
		}
		else
		{
			fputc(first, pfWrite);
			ungetc(second, pfRead);
			//state = C_STATE;
		}
		break;
	//case '/':			//    /*suuhch/*acizdij*/
	//	second = fgetc(pfRead);
	//	if ((second == '*') || (second == '/'))
	//	{
	//		fputc(' ', pfWrite);
	//	}
	//	else if ('\n' == second)
	//	{
	//		fputc(second, pfWrite);
	//		fputc('/', pfWrite);
	//		fputc('/', pfWrite);
	//	}
	//	else
	//	{
	//		fputc(first, pfWrite);
	//		fputc(second, pfWrite);
	//	}
	//	break;
	case '\n':
		fputc(first, pfWrite);
		fputc('/', pfWrite);
		fputc('/', pfWrite);
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}

void Do_CPP_State(FILE * pfRead, FILE * pfWrite)
{
	int first = 0;
	int second = 0;
	static int flag = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '\n':
		fputc(first, pfWrite);
		state = NULL_STATE;
		break;
	case EOF:
		fputc(first, pfWrite);
		state = END_STATE;
		break;
	//case '/':
	//	second = fgetc(pfRead);
	//	if ('*' == second)
	//	{
	//		fputc(' ', pfWrite);
	//		flag = 1;//C++◊¢ ÕŒ Ã‚
	//	}
	//	else
	//	{
	//		fputc(first, pfWrite);
	//		fputc(second, pfWrite);
	//	}
	//	break;
	//case '*':
	//	if (flag == 1)
	//	{
	//		second = fgetc(pfRead);
	//		if (second == '/')
	//			flag = 0;
	//		fputc(' ', pfWrite);
	//	}
	//	else
	//	{
	//		fputc(first, pfWrite);
	//	}
	//	break;
	default:
		fputc(first, pfWrite);
		break;
	}
}

void Do_STR_State(FILE *pfRead, FILE *pfWrite)
{
	int first = 0;
	first = fgetc(pfRead);
	switch (first)
	{
	case '"':
		state = NULL_STATE;
		fputc(first, pfWrite);
		break;
	default:
		fputc(first,pfWrite);
		break;
	}
}

void comment_convert(FILE * pfRead, FILE * pfWrite)
{
	while (state != END_STATE)
	{
		switch (state)
		{
		case NULL_STATE:
			Do_Null_State(pfRead, pfWrite);
			break;
		case C_STATE:
			Do_C_State(pfRead, pfWrite);
			break;
		case CPP_STATE:
			Do_CPP_State(pfRead, pfWrite);
			break;
		case STR_STATE:
			Do_STR_State(pfRead, pfWrite);
			break;
		case END_STATE:
			break;
		}
	}
}