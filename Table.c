#include "TableRecord.h"
#include "Functions.h"
#include "Table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//---------------------------------------------------------------------------------
// Функция создает массив структур TableRecord (массив записей файла tab_MM_YYYY.txt)
Table* create_Table()
	{
	return (Table*)calloc(1, sizeof(Table));
	}

//---------------------------------------------------------------------------------
// Функция "инициализирует" массив структур
// Вх. данные: файл с записями, структура, на основании которой будет создаваться массив
void init_Table(FILE* file, Table* structure)
	{
	char* L = fread_string(file);
	structure->length = atoi(L);
	free(L);
	structure->table = (TableRecord**)calloc(structure->length, sizeof(TableRecord*));
	for (int i = 0; i < structure->length; i++)
		{
		char* tmp = fread_string(file);
		TableRecord* record = create_TableRecord();
		init_TableRecord(record, tmp);
		structure->table[i] = record;
		free(tmp);
		}
	}

//---------------------------------------------------------------------------------
// Функция добавляет запись TableRecord
// Вх. данные: структура, в которую добавляется запись, запись
void add_TableRecord(Table* structure, TableRecord* record)
	{
	structure->length++;
	structure->table = (TableRecord**)realloc(structure->table, structure->length * sizeof(TableRecord*));
	structure->table[structure->length - 1] = record;
	}

int check_S_aud(TableRecord* record,Table* table, Catalog* catalog)
	{
	int sum_hours= 0;
	for (int i = 0; i < table->length; i++)
		{
		if (!strcmp(get_TableRecord_shortname(table->table[i]), get_TableRecord_shortname(record)))
			{
			sum_hours += get_TableRecord_audhours(table->table[i]);
			}
		}
	CatalogRecord* catalog_record = get_CatalogRecord_by_shortname(get_TableRecord_shortname(record),catalog);
	if (catalog_record != NULL)
		{
		if (get_CatalogRecord_aud_hours(catalog_record) >= sum_hours)
			{
			return 1;
			}
		}
	return 0;
	}

int get_S_aud_month(char* shortname, Table* table)
	{
	int S_aud_month = 0;
	for (int i = 0; i < table->length; i++)
		{
		if (!strcmp(get_TableRecord_shortname(table->table[i]), shortname))
			{
			S_aud_month += get_TableRecord_audhours(table->table[i]);
			}
		}
	return S_aud_month;
	}

//---------------------------------------------------------------------------------
// Функция освобождает память Table
// Вх. данные: структура
void delete_Table(Table* structure)
	{
	for (int i = 0; i < structure->length; i++)
		delete_TableRecord(structure->table[i]);
	free(structure->table);
	free(structure);
	}