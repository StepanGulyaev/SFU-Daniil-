#include "InputRecord.h"
#include "Functions.h"
#include "Input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------------
// ������� �������� ������ ��� ������ inputTT.txt
Input* create_Input()
	{
	return (Input*)calloc(1, sizeof(Input));
	}

//---------------------------------------------------------------------------------
// ������� "��������������" ������� ���� inputTT.txt
// ��. ������: ������� ����, ���������
void init_Input(FILE* file, Input* structure)
	{
	structure->length = 1;
	structure->input = (InputRecord**)calloc(structure->length, sizeof(InputRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		InputRecord* record = create_InputRecord();
		init_InputRecord(record, tmp);
		structure->input[i] = record;
		free(tmp);
		}
	}

//---------------------------------------------------------------------------------
// ������� ����������� ������ Input
void delete_Input(Input* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_InputRecord(structure->input[i]);
	free(structure->input);
	free(structure);
	}