#include "CatalogRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------
// Функция выделяет место для записи строки из файла Catalog.txt
// Вх. данные: ничего
CatalogRecord* create_CatalogRecord()
	{
	return (CatalogRecord*)calloc(1, sizeof(CatalogRecord));
	}

//---------------------------------------------------------------------
// Функция заносит данные строки Catalog.txt в структуру CatalogRecord (инициализирует)
// Вх. данные: инициализируемая структура, строка Catalog.txt
void init_CatalogRecord(CatalogRecord* structure, char* str)
	{
	//выделение места для имен
	structure->ShortName = (char*)calloc(0, sizeof(char));
	structure->FullName = (char*)calloc(0, sizeof(char));
	//info для всех полей CatalogRecord (записи строки Catalog.txt)
	char** info = separate_CatalogRecord_string(str);
	set_CatalogRecord_shortname(structure, info[0]);
	set_CatalogRecord_hours(structure, atoi(info[1]));
	set_CatalogRecord_aud_hours(structure, atoi(info[2]));
	set_CatalogRecord_fullname(structure, info[3]);
	for (int i = 0; i < 4; i++)
		free(info[i]);
	free(info);
	}

//---------------------------------------------------------------------
// Функция возвращает краткое название программы записи Catalog.txt
// Вх. данные: структура
char* get_CatalogRecord_shortname(CatalogRecord* structure)
	{
	return structure->ShortName;
	}

//---------------------------------------------------------------------
// Функция возвращает общее количество часов по программе записи Catalog.txt
// Вх. данные: структура
int get_CatalogRecord_hours(CatalogRecord* structure)
	{
	return structure->Hours;
	}

//---------------------------------------------------------------------
// Функция возвращает количество часов аудиторных занятий записи Catalog.txt
// Вх. данные: структура
int get_CatalogRecord_aud_hours(CatalogRecord* structure)
	{
	return structure->AudHours;
	}
//---------------------------------------------------------------------
// Функция возвращает полное наименование программы записи Catalog.txt
// Вх. данные: структура
char* get_CatalogRecord_fullname(CatalogRecord* structure)
	{
	return structure->FullName;
	}

//---------------------------------------------------------------------
// Функция присваивает имя короткому имени программы в структуре
// Вх. данные: структура, короткое имя
void set_CatalogRecord_shortname(CatalogRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

//---------------------------------------------------------------------
// Функция присваивает бщее количество часов по программе в структуре
// Вх. данные: структура, короткое имя
void set_CatalogRecord_hours(CatalogRecord* structure, int Hours)
	{
	structure->Hours = Hours;
	}

//---------------------------------------------------------------------
// Функция присваивает количество часов аудиторных занятий в структуре
// Вх. данные: структура, короткое имя
void set_CatalogRecord_aud_hours(CatalogRecord* structure, int AudHours)
	{
	structure->AudHours = AudHours;
	}

//---------------------------------------------------------------------
// Функция присваивает полное наименование программы в структуре
// Вх. данные: структура, короткое имя
void set_CatalogRecord_fullname(CatalogRecord* structure, char* FullName)
	{
	structure->FullName = (char*)realloc(structure->FullName, (strlen(FullName) + 1) * sizeof(char));
	strcpy(structure->FullName, FullName);
	}

//---------------------------------------------------------------------
// Функция делит запись Catalog.txt на части и присваивает их значения соответствующим полям
// Вх. данные: строка, которую нужно поделить
char** separate_CatalogRecord_string(char* str)
	{
	char** info = (char**)calloc(4, sizeof(char*));
	char* ShortName = strtok(str, " ");
	info[0] = (char*)calloc(strlen(ShortName) + 1, sizeof(char));
	char* Hours = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(Hours) + 1, sizeof(char));
	char* AkademHours = strtok(NULL, " ");
	info[2] = (char*)calloc(strlen(AkademHours) + 1, sizeof(char));
	char* FullName = strtok(NULL, "");
	info[3] = (char*)calloc(strlen(FullName) + 1, sizeof(char));
	strcpy(info[0], ShortName);
	strcpy(info[1], Hours);
	strcpy(info[2], AkademHours);
	strcpy(info[3], FullName);
	return info;
	}

//---------------------------------------------------------------------
// Функция освообждает память структуры CatalogRecord
void delete_CatalogRecord(CatalogRecord* structure)
	{
	free(structure->ShortName);
	free(structure->FullName);
	free(structure);
	}
