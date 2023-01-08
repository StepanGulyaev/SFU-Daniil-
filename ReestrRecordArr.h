#ifndef REESTRRECORDARR_H
#define REESTRRECORDARR_H

#include "ReestrRecord.h"
#include "Reestr.h"
#include "Input.h"
#include "TableRecordArr.h"
#include <stdio.h>

typedef struct ReestrRecordArr
    {
    ReestrRecord** reestr_record_arr;
    size_t size;
    } ReestrRecordArr;

ReestrRecordArr* create_ReestrRecordArr();
void init_ReestrRecordArr(ReestrRecordArr*);
void push_to_ReestrRecordArr(ReestrRecord*, ReestrRecordArr*);
void find_ReestrRecords_with_ShortName(ReestrRecordArr*,TableRecordArr*,Reestr*,Input*);
void delete_ReestrRecordArr(ReestrRecordArr*);

#endif