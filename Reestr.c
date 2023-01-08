#include "ReestrRecord.h"
#include "Functions.h"
#include "Reestr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------------
// Функция создает массив структур ReestrRecord (массив записей файла Reestr.txt)
Reestr* create_Reestr()
	{
	return (Reestr*)calloc(1, sizeof(Reestr));
	}

//---------------------------------------------------------------------------------
// Функция "инициализирует" массив структур
// Вх. данные: файл с записями, структура, на основании которой будет создаваться массив
void init_Reestr(FILE* file, Reestr* structure)
	{
	char* Q = fread_string(file);
	structure->length = atoi(Q);
	free(Q);
	structure->reestr = (ReestrRecord**)calloc(structure->length, sizeof(ReestrRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		ReestrRecord* record = create_ReestrRecord();
		init_ReestrRecord(record, tmp);
		structure->reestr[i] = record;
		free(tmp);
		}
	}

//---------------------------------------------------------------------------------
// Функция добавляет запись ReestrRecord
// Вх. данные: структура, в которую добавляется запись, запись
void add_ReestrRecord(Reestr* structure, ReestrRecord* record)
	{
	structure->length++;
	structure->reestr = (ReestrRecord**)realloc(structure->reestr, structure->length * sizeof(ReestrRecord*));
	structure->reestr[structure->length - 1] = record;
	}

//---------------------------------------------------------------------------------
// Функция освобождает память Reestr
// Вх. данные: структура
void delete_Reestr(Reestr* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_ReestrRecord(structure->reestr[i]);
	free(structure->reestr);
	free(structure);
	}