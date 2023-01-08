#ifndef INPUT_H
#define INPUT_H

#include "InputRecord.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Input
	{
	InputRecord** input;
	size_t length;
	} Input;

Input* create_Input();
void init_Input(FILE* file, Input* structure);
void delete_Input(Input* structure);

#endif
