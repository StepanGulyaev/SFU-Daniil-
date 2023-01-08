#ifndef OUTPUTDETAIL_H
#define OUTPUTDETAIL_H

#include "TableRecordArr.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include <string.h>

typedef struct OutputDetail
	{
	char* ProgramName;
	int NumH;
	int S_aud;
	double PH;
	double SumProg;
	} OutputDetail;

OutputDetail* create_OutputDetail();
void init_OutputDetail(OutputDetail* output_detail, TableRecord* table_record, ReestrRecord* reestr_record, Catalog* catalog, Table* table);
void delete_OutputDetail(OutputDetail* output_detail);




#endif 
