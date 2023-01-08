#include "ReestrRecord.h"
#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------
// Функция выделяет место для записи строки из файла Reestr.txt
// Вх. данные: ничего
ReestrRecord* create_ReestrRecord()
	{
	return (ReestrRecord*)calloc(1, sizeof(ReestrRecord));
	}

//---------------------------------------------------------------------
// Функция заносит данные строки Reestr.txt в структуру ReestrRecord (инициализирует)
// Вх. данные: инициализируемая структура, строка Reestr.txt
void init_ReestrRecord(ReestrRecord* structure, char* str)
	{
	//выделение места для имени и дат
	structure->ShortName = (char*)calloc(0, sizeof(char));
	structure->RealizationBeginningMonth = (char*)calloc(0, sizeof(char));
	structure->RealizationBeginningYear = (char*)calloc(0, sizeof(char));
	structure->RealizationEndingMonth = (char*)calloc(0, sizeof(char));
	structure->RealizationEndingYear = (char*)calloc(0, sizeof(char));
	//info для всех полей ReestrRecord (записи строки Reestr.txt)
	char** info = separate_ReestrRecord_string(str);
	set_ReestrRecord_shortname(structure, info[0]);
	char* info1_copy = (char*)calloc(strlen(info[1]) + 1, sizeof(char));
	strcpy(info1_copy, info[1]);
	char** date = separate_date(info1_copy);
	set_ReestrRecord_realization_beginning_month(structure, date[0]);
	set_ReestrRecord_realization_beginning_year(structure, date[1]);
	char* info2_copy = (char*)calloc(strlen(info[2]) + 1, sizeof(char));
	strcpy(info2_copy, info[2]);
	char** date1 = separate_date(info2_copy);
	set_ReestrRecord_realization_ending_month(structure, date1[0]);
	set_ReestrRecord_realization_ending_year(structure, date1[1]);
	set_ReestrRecord_price(structure, atoi(info[3]));
	set_ReestrRecord_students_amount(structure, atoi(info[4]));
	set_ReestrRecord_groups_amount(structure, atoi(info[5]));
	for (int i = 0; i < 6; i++)
		free(info[i]);
	free(info);
	for (int i = 0; i < 2; i++)
		free(date[i]);
	for (int i = 0; i < 2; i++)
		free(date1[i]);
	free(date);
	free(date1);
	free(info1_copy);
	free(info2_copy);
	}

//---------------------------------------------------------------------
// Функция возвращает краткое название программы записи Reestr.txt
// Вх. данные: структура
char* get_ReestrRecord_shortname(ReestrRecord* structure)
	{
	return structure->ShortName;
	}
//---------------------------------------------------------------------

//---------------------------------------------------------------------
// Функция возвращает месяц начала реализации программы записи Reestr.txt
// Вх. данные: структура
char* get_ReestrRecord_realization_beginning_month(ReestrRecord* structure)
	{
	return structure->RealizationBeginningMonth;
	}
//---------------------------------------------------------------------
// Функция возвращает год начала реализации программы записи Reestr.txt
// Вх. данные: структура
char* get_ReestrRecord_realization_beginning_year(ReestrRecord* structure)
	{
	return structure->RealizationBeginningYear;
	}

//---------------------------------------------------------------------
// Функция возвращает месяц окончания реализации программы записи Reestr.txt
// Вх. данные: структура
char* get_ReestrRecord_realization_ending_month(ReestrRecord* structure)
	{
	return structure->RealizationEndingMonth;
	}

//---------------------------------------------------------------------
// Функция возвращает год окончания реализации программы записи Reestr.txt
// Вх. данные: структура
char* get_ReestrRecord_realization_ending_year(ReestrRecord* structure)
	{
	return structure->RealizationEndingYear;
	}

//---------------------------------------------------------------------
// Функция возвращает стоимость обучения на программе записи Reestr.txt
// Вх. данные: структура
int get_ReestrRecord_price(ReestrRecord* structure)
	{
	return structure->Price;
	}

//---------------------------------------------------------------------
// Функция возвращает количество обучающихся на программе записи Reestr.txt
// Вх. данные: структура
int get_ReestrRecord_students_amount(ReestrRecord* structure)
	{
	return structure->StudentsAmount;
	}

//---------------------------------------------------------------------
// Функция возвращает количество групп на программе записи Reestr.txt
// Вх. данные: структура
int get_ReestrRecord_groups_amount(ReestrRecord* structure)
	{
	return structure->GroupsAmount;
	}

//---------------------------------------------------------------------
// Функция присваивает имя короткому имени программы в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_shortname(ReestrRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

//---------------------------------------------------------------------
// Функция присваивает месяц начала реализации программы в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_realization_beginning_month(ReestrRecord* structure, char* RealizationBeginning)
	{
	structure->RealizationBeginningMonth = (char*)realloc(structure->RealizationBeginningMonth, (strlen(RealizationBeginning) + 1) * sizeof(char));
	strcpy(structure->RealizationBeginningMonth, RealizationBeginning);
	}

//---------------------------------------------------------------------
// Функция присваивает год начала реализации программы в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_realization_beginning_year(ReestrRecord* structure, char* RealizationBeginning)
	{
	structure->RealizationBeginningYear = (char*)realloc(structure->RealizationBeginningYear, (strlen(RealizationBeginning) + 1) * sizeof(char));
	strcpy(structure->RealizationBeginningYear, RealizationBeginning);
	}

//---------------------------------------------------------------------
// Функция присваивает месяц окончания реализации программы в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_realization_ending_month(ReestrRecord* structure, char* RealizationEnding)
	{
	structure->RealizationEndingMonth = (char*)realloc(structure->RealizationEndingMonth, (strlen(RealizationEnding) + 1) * sizeof(char));
	strcpy(structure->RealizationEndingMonth, RealizationEnding);
	}

//---------------------------------------------------------------------
// Функция присваивает год окончания реализации программы в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_realization_ending_year(ReestrRecord* structure, char* RealizationEnding)
	{
	structure->RealizationEndingYear = (char*)realloc(structure->RealizationEndingYear, (strlen(RealizationEnding) + 1) * sizeof(char));
	strcpy(structure->RealizationEndingYear, RealizationEnding);
	}

//---------------------------------------------------------------------
// Функция присваивает стоимость обучения на программе в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_price(ReestrRecord* structure, int Price)
	{
	structure->Price = Price;
	}

//---------------------------------------------------------------------
// Функция присваивает количество обучающихся на программе в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_students_amount(ReestrRecord* structure, int StudentsAmount)
	{
	structure->StudentsAmount = StudentsAmount;
	}

//---------------------------------------------------------------------
// Функция присваивает количество групп на программее в структуре
// Вх. данные: структура, короткое имя
void set_ReestrRecord_groups_amount(ReestrRecord* structure, int GroupsAmount)
	{
	structure->GroupsAmount = GroupsAmount;
	}

//---------------------------------------------------------------------
// Функция делит запись Reestr.txt на поля и присваивает их 
// Вх. данные: строка, которую нужно поделить
char** separate_ReestrRecord_string(char* str)
	{
	char** info = (char**)calloc(6, sizeof(char*));
	char* ShortName = strtok(str, " ");
	info[0] = (char*)calloc(strlen(ShortName) + 1, sizeof(char));
	char* RealizationBeginning = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(RealizationBeginning) + 1, sizeof(char));
	char* RealizationEnding = strtok(NULL, " ");
	info[2] = (char*)calloc(strlen(RealizationEnding) + 1, sizeof(char));
	char* Price = strtok(NULL, " ");
	info[3] = (char*)calloc(strlen(Price) + 1, sizeof(char));
	char* StudentsAmount = strtok(NULL, " ");
	info[4] = (char*)calloc(strlen(StudentsAmount) + 1, sizeof(char));
	char* GroupsAmount = strtok(NULL, "");
	info[5] = (char*)calloc(strlen(GroupsAmount) + 1, sizeof(char));
	strcpy(info[0], ShortName);
	strcpy(info[1], RealizationBeginning);
	strcpy(info[2], RealizationEnding);
	strcpy(info[3], Price);
	strcpy(info[4], StudentsAmount);
	strcpy(info[5], GroupsAmount);
	return info;
	}

//---------------------------------------------------------------------
// Функция освообждает память
void delete_ReestrRecord(ReestrRecord* structure)
	{
	free(structure->ShortName);
	free(structure->RealizationBeginningMonth);
	free(structure->RealizationBeginningYear);
	free(structure->RealizationEndingMonth);
	free(structure->RealizationEndingYear);
	free(structure);
	}
