#include "TableRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------
// ‘ункци€ выдел€ет место дл€ записи строки из файла Table.txt
// ¬х. данные: ничего
TableRecord* create_TableRecord()
	{
	return (TableRecord*)calloc(1, sizeof(TableRecord));
	}

//---------------------------------------------------------------------
// ‘ункци€ заносит данные строки Table.txt в структуру TableRecord (инициализирует)
// ¬х. данные: инициализируема€ структура, строка Table.txt
void init_TableRecord(TableRecord* structure, char* str)
	{
	//выделение места дл€ имен
	structure->FamilyIO = (char*)calloc(0, sizeof(char));
	structure->ShortName = (char*)calloc(0, sizeof(char));
	//info дл€ всех полей TableRecord (записи строки Table.txt)
	char** info = separate_TableRecord_string(str);
	set_TableRecord_familyio(structure, info[0]);
	set_TableRecord_shortname(structure, info[1]);
	set_TableRecord_audhours(structure, atoi(info[2]));
	for (int i = 0; i < 3; i++)
		free(info[i]);
	free(info);
	}

//---------------------------------------------------------------------
// ‘ункци€ возвращает фамилию и инициалы преподавател€ записи Table.txt
// ¬х. данные: структура
char* get_TableRecord_famiilyio(TableRecord* structure)
	{
	return structure->FamilyIO;
	}

//---------------------------------------------------------------------
// ‘ункци€ возвращает краткое наименование программы записи Table.txt
// ¬х. данные: структура
char* get_TableRecord_shortname(TableRecord* structure)
	{
	return structure->ShortName;
	}

//---------------------------------------------------------------------
// ‘ункци€ возвращает количество аудиторных часов, отработанных на программе за мес€ц записи Table.txt
// ¬х. данные: структура
int get_TableRecord_audhours(TableRecord* structure)
	{
	return structure->AudHours;
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает фамилию и инициалы преподавател€ в структуре
// ¬х. данные: структура, короткое им€
void set_TableRecord_familyio(TableRecord* structure, char* FamilyIO)
	{
	structure->FamilyIO = (char*)realloc(structure->FamilyIO, (strlen(FamilyIO) + 1) * sizeof(char));
	strcpy(structure->FamilyIO, FamilyIO);
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает краткое наименование программы в структуре
// ¬х. данные: структура, короткое им€
void set_TableRecord_shortname(TableRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

//---------------------------------------------------------------------
// ‘ункци€ присваивает количество аудиторных часов, отработанных на программе за мес€ц в структуре
// ¬х. данные: структура, короткое им€
void set_TableRecord_audhours(TableRecord* structure, int AudHours)
	{
	structure->AudHours = AudHours;
	}

//---------------------------------------------------------------------
// ‘ункци€ делит запись Table.txt на пол€ и присваивает их 
// ¬х. данные: строка, которую нужно поделить
char** separate_TableRecord_string(char* str)
	{
	char** info = (char**)calloc(4, sizeof(char*));
	char* FamilyIO = strtok(str, " ");
	info[0] = (char*)calloc(strlen(FamilyIO) + 1, sizeof(char));
	char* ShortName = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(ShortName) + 1, sizeof(char));
	char* AudHours = strtok(NULL, "");
	info[2] = (char*)calloc(strlen(AudHours) + 1, sizeof(char));
	strcpy(info[0], FamilyIO);
	strcpy(info[1], ShortName);
	strcpy(info[2], AudHours);
	return info;
	}

//---------------------------------------------------------------------
// ‘ункци€ освообждает пам€ть
void delete_TableRecord(TableRecord* structure)
	{
	free(structure->FamilyIO);
	free(structure->ShortName);
	free(structure);
	}