#pragma once

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE  "input.c"
#define OUTPUT_FILE  "output.c"

enum  STATE
{
	NULL_STATE,
	C_STATE,
	CPP_STATE,
	STR_STATE,
	END_STATE
};

void comment_convert(FILE * pfRead, FILE * pfWrite);
void Do_Null_State(FILE * pfRead, FILE * pfWrite);
void Do_C_State(FILE * pfRead, FILE * pfWrite);
void Do_CPP_State(FILE * pfRead, FILE * pfWrite);

