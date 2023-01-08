#include "ReestrRecordArr.h"
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------
// Функция создает массив записей реестра
ReestrRecordArr* create_ReestrRecordArr()
    {
    return (ReestrRecordArr*)calloc(1, sizeof(ReestrRecordArr));
    }

//---------------------------------------------------------------------
// Функция "инициализриует" массив записей реестра
void init_ReestrRecordArr(ReestrRecordArr* to_construct)
    {
    to_construct->size = 0;
    to_construct->reestr_record_arr = calloc(1, sizeof(to_construct->reestr_record_arr));
    }

//---------------------------------------------------------------------
// Функция ...
void push_to_ReestrRecordArr(ReestrRecord* to_push, ReestrRecordArr* ReestrRecordArr)
    {
    ReestrRecordArr->size++;
    ReestrRecordArr->reestr_record_arr = (ReestrRecord**)realloc(ReestrRecordArr->reestr_record_arr, ReestrRecordArr->size * sizeof(ReestrRecord*));
    ReestrRecordArr->reestr_record_arr[ReestrRecordArr->size - 1] = to_push;
    }

void find_ReestrRecords_with_ShortName(ReestrRecordArr* reestr_arr,TableRecordArr* table_arr, Reestr* reestr,Input* input)
    {
    for (int i = 0; i < reestr->length; i++)
        {
        for (int j = 0; j < table_arr->size; j++)
            {
            if (!strcmp(get_ReestrRecord_shortname(reestr->reestr[i]), get_TableRecord_shortname(table_arr->table_record_arr[j])))
                {
                int realization_beginning_month = atoi(get_ReestrRecord_realization_beginning_month(reestr->reestr[i]));
                int realization_beginning_year = atoi(get_ReestrRecord_realization_beginning_year(reestr->reestr[i]));
                int realization_ending_month = atoi(get_ReestrRecord_realization_ending_month(reestr->reestr[i]));
                int realization_ending_year = atoi(get_ReestrRecord_realization_ending_year(reestr->reestr[i]));
                int input_month = atoi(get_InputRecord_month(input->input[0]));
                int input_year = atoi(get_InputRecord_year(input->input[0]));
                if ( (input_year > realization_beginning_year && input_year < realization_ending_year) ||
                (input_year == realization_beginning_year && input_month >= realization_beginning_month) ||
                (input_year == realization_ending_year && input_month <= realization_ending_month))
                    {
                    push_to_ReestrRecordArr(reestr->reestr[i], reestr_arr);
                    }
                }
            }
        }
    }

//---------------------------------------------------------------------
// Функция освобождает память массива записей реестра
void delete_ReestrRecordArr(ReestrRecordArr* structure)
    {
    free(structure->reestr_record_arr);
    free(structure);
    }