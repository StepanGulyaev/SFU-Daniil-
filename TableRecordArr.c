
#include <stdio.h>
#include <stdlib.h>
#include "TableRecordArr.h"

//---------------------------------------------------------------------
// Функция создает массив записей табеля
TableRecordArr* create_TableRecordArr()
    {
    return (TableRecordArr*)calloc(1, sizeof(TableRecordArr));
    }

//---------------------------------------------------------------------
// Функция "инициализриует" массив записей табеля
void init_TableRecordArr(TableRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->table_record_arr = calloc(1, sizeof(to_construct->table_record_arr));
    }

//---------------------------------------------------------------------
// Функция ...
void push_to_TableRecordArr(TableRecord* to_push, TableRecordArr* TableRecordArr)
    {
    TableRecordArr->size++;
    TableRecordArr->table_record_arr = (TableRecord**)realloc(TableRecordArr->table_record_arr, TableRecordArr->size * sizeof(TableRecord*));
    TableRecordArr->table_record_arr[TableRecordArr->size - 1] = to_push;
    }

void find_TableRecords_with_FamilyIO(TableRecordArr* table_arr,Table* table,Input* input,Catalog* catalog)
    {
    for (int i = 0; i < table->length; i++)
        {
        if (!strcmp(table->table[i]->FamilyIO, input->input[0]->FamilyIO))
            {
            if (check_S_aud(table->table[i],table,catalog))
                {
                push_to_TableRecordArr(table->table[i], table_arr);
                }
            }
        }
    }

//---------------------------------------------------------------------
// Функция освобождает память массива записей табеля
void delete_TableRecordArr(TableRecordArr* structure)
    {
    free(structure->table_record_arr);
    free(structure);
    }