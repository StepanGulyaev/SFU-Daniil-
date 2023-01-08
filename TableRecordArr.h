#ifndef TABLERECORDARR_H
#define TABLERECORDARR_H

#include <stdio.h>
#include "Catalog.h"
#include "TableRecord.h"
#include "Input.h"
#include "Table.h"

typedef struct TableRecordArr
    {
    TableRecord** table_record_arr;
    size_t size;
    } TableRecordArr;

TableRecordArr* create_TableRecordArr();
void init_TableRecordArr(TableRecordArr*);
void push_to_TableRecordArr(TableRecord*, TableRecordArr*);
void find_TableRecords_with_FamilyIO(TableRecordArr*,Table*,Input*);
void delete_TableRecordArr(TableRecordArr*);

#endif