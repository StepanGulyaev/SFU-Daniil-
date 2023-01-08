#ifndef TABLE_H
#define TABLE_H

#include "TableRecord.h"
#include "Catalog.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Table
	{
	TableRecord** table;
	size_t length;
	} Table;

Table* create_Table();
void init_Table(FILE* file, Table* structure);
void add_TableRecord(Table* structure, TableRecord*);
int check_S_aud(TableRecord* record,Table* table,Catalog* catalog);
int get_S_aud_month(char* shortname,Table* table);
void delete_Table(Table* structure);

#endif 