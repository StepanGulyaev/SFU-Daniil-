#include "Output.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include "Input.h"
#include "OutputDetail.h"
#include "TableRecordArr.h"
#include "ReestrRecordArr.h"
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------
// ‘ункци€ выдел€ет место дл€ записи строки outputTT.txt
Output* create_Output()
	{
	return (Output*)calloc(1, sizeof(Output));
	}

//---------------------------------------------------------------------------------
// ‘ункци€ "инициализирует" выходной файл outputTT.txt
// ¬х. данные: входной файл, структура
void init_Output(Catalog* catalog, Reestr* reestr, Input* input, Output* output)
	{
	char* tmp = (char*)calloc(16, sizeof(char));
	sprintf(tmp, "tab_%s_%s.txt", get_InputRecord_month(input->input[0]), get_InputRecord_year(input->input[0]));
	FILE* ftable = fopen(tmp, "r");
	free(tmp);
	output->FamilyIO = (char*)calloc(strlen(input->input[0]->FamilyIO) + 1, sizeof(char));
	output->Month = (char*)calloc(strlen(input->input[0]->Month) + 1, sizeof(char));
	output->Year = (char*)calloc(strlen(input->input[0]->Year) + 1, sizeof(char));
	set_Output_FamilyIO(output, input->input[0]->FamilyIO);
	set_Output_Month(output, input->input[0]->Month);
	set_Output_Year(output, input->input[0]->Year);
	if (!check_file(ftable))
		{
		set_Output_DetailNum_s(output,"Error");
		output->DetailNum = 0;
		set_Output_Result(output,0);
		}
	else
		{
		Table* table = create_Table();
		init_Table(ftable, table);

		TableRecordArr* table_arr = create_TableRecordArr();
		init_TableRecordArr(table_arr);
		find_TableRecords_with_FamilyIO(table_arr,table,input,catalog);

		ReestrRecordArr* reestr_arr = create_ReestrRecordArr();
		init_ReestrRecordArr(reestr_arr);
		find_ReestrRecords_with_ShortName(reestr_arr,table_arr,reestr,input);

		if (table_arr->size == 0 || reestr_arr->size == 0)
			{
			set_Output_DetailNum_s(output, "Error");
			output->DetailNum = 0;
			set_Output_Result(output, 0);
			}
		else 
			{
			for (int i = 0; i < table_arr->size; i++)
				{
				for (int j = 0; j < reestr_arr->size; j++)
					{
					if (!strcmp(get_ReestrRecord_shortname(reestr_arr->reestr_record_arr[j]), 
					get_TableRecord_shortname(table_arr->table_record_arr[i])))
						{
						OutputDetail* detail = create_OutputDetail();
						init_OutputDetail(detail,table_arr->table_record_arr[i],reestr_arr->reestr_record_arr[j],catalog,table);
						push_to_Details(detail,output);
						}
					}
				}
			int size = (output->DetailNum / 10) + 2;
			char* buf = (char*)calloc(size,sizeof(char));
			_itoa(output->DetailNum,buf,10);
			set_Output_DetailNum_s(output, buf);
			delete_TableRecordArr(table_arr);
			delete_ReestrRecordArr(reestr_arr);
			free(buf);
			}
		delete_Table(table);
		fclose(ftable);
		}
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает фамилию и инициалы преподавател€ в структуре
// ¬х. данные: структура, фамили€ и инициалы
void set_Output_FamilyIO(Output* structure, char* FamilyIO)
	{
	structure->FamilyIO = (char*)realloc(structure->FamilyIO, (strlen(FamilyIO) + 1) * sizeof(char));
	strcpy(structure->FamilyIO, FamilyIO);
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает мес€ц расчетного периода в структуре
// ¬х. данные: структура, мес€ц расчетного периода
void set_Output_Month(Output* structure, char* Month)
	{
	structure->Month = (char*)realloc(structure->Month, (strlen(Month) + 1) * sizeof(char));
	strcpy(structure->Month, Month);
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает год расчетного периода в структуре
// ¬х. данные: структура, год расчетного периода
void set_Output_Year(Output* structure, char* Year)
	{
	structure->Year = (char*)realloc(structure->Year, (strlen(Year) + 1) * sizeof(char));
	strcpy(structure->Year, Year);
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает рассчитанное итоговое значение в структуре
// ¬х. данные: структура, рассчитанное итоговое значение
void set_Output_Result(Output* structure, double Result)
	{
	structure->Result = Result;
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает строку детализации в структуре
// ¬х. данные: структура, строка детализации
void set_Output_DetailNum_s(Output* structure, char* DetailNum_s)
	{
	structure->DetailNum_s = (char*)realloc(structure->DetailNum_s, (strlen(DetailNum_s) + 1) * sizeof(char));
	strcpy(structure->DetailNum_s, DetailNum_s);
	}

void push_to_Details(OutputDetail* detail, Output* output)
	{
	output->DetailNum++;
	output->Details = (OutputDetail**)realloc(output->Details, output->DetailNum * sizeof(OutputDetail*));
	output->Details[output->DetailNum - 1] = detail;
	}

void print_Output(Output* output)
	{
	FILE* foutput = fopen("output.txt","w");
	fprintf(foutput,"%s %s.%s %s\n",output->FamilyIO,output->Month,output->Year,output->DetailNum_s);
	for (int i = 0; i < output->DetailNum; i++)
		{
		output->Result += output->Details[i]->SumProg;
		fprintf(foutput,"%s %d (from %d) %lf %lf\n",output->Details[i]->ProgramName,
		output->Details[i]->NumH,output->Details[i]->S_aud,output->Details[i]->PH, output->Details[i]->SumProg);
		}
	fprintf(foutput,"TOTAL %s %lf\n",output->FamilyIO,output->Result);
	fclose(foutput);
	}

void delete_Output(Output* output)
	{
	free(output->FamilyIO);
	free(output->Month);
	free(output->Year);
	free(output->DetailNum_s);
	for (int i = 0; i < output->DetailNum; i++)
		{
		delete_OutputDetail(output->Details[i]);
		}
	free(output->Details);
	free(output);
	}