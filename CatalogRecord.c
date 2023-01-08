#include "CatalogRecord.h"
#include "Functions.h"
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------
// ������� �������� ����� ��� ������ ������ �� ����� Catalog.txt
// ��. ������: ������
CatalogRecord* create_CatalogRecord()
	{
	return (CatalogRecord*)calloc(1, sizeof(CatalogRecord));
	}

//---------------------------------------------------------------------
// ������� ������� ������ ������ Catalog.txt � ��������� CatalogRecord (��������������)
// ��. ������: ���������������� ���������, ������ Catalog.txt
void init_CatalogRecord(CatalogRecord* structure, char* str)
	{
	//��������� ����� ��� ����
	structure->ShortName = (char*)calloc(0, sizeof(char));
	structure->FullName = (char*)calloc(0, sizeof(char));
	//info ��� ���� ����� CatalogRecord (������ ������ Catalog.txt)
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
// ������� ���������� ������� �������� ��������� ������ Catalog.txt
// ��. ������: ���������
char* get_CatalogRecord_shortname(CatalogRecord* structure)
	{
	return structure->ShortName;
	}

//---------------------------------------------------------------------
// ������� ���������� ����� ���������� ����� �� ��������� ������ Catalog.txt
// ��. ������: ���������
int get_CatalogRecord_hours(CatalogRecord* structure)
	{
	return structure->Hours;
	}

//---------------------------------------------------------------------
// ������� ���������� ���������� ����� ���������� ������� ������ Catalog.txt
// ��. ������: ���������
int get_CatalogRecord_aud_hours(CatalogRecord* structure)
	{
	return structure->AudHours;
	}
//---------------------------------------------------------------------
// ������� ���������� ������ ������������ ��������� ������ Catalog.txt
// ��. ������: ���������
char* get_CatalogRecord_fullname(CatalogRecord* structure)
	{
	return structure->FullName;
	}

//---------------------------------------------------------------------
// ������� ����������� ��� ��������� ����� ��������� � ���������
// ��. ������: ���������, �������� ���
void set_CatalogRecord_shortname(CatalogRecord* structure, char* ShortName)
	{
	structure->ShortName = (char*)realloc(structure->ShortName, (strlen(ShortName) + 1) * sizeof(char));
	strcpy(structure->ShortName, ShortName);
	}

//---------------------------------------------------------------------
// ������� ����������� ���� ���������� ����� �� ��������� � ���������
// ��. ������: ���������, �������� ���
void set_CatalogRecord_hours(CatalogRecord* structure, int Hours)
	{
	structure->Hours = Hours;
	}

//---------------------------------------------------------------------
// ������� ����������� ���������� ����� ���������� ������� � ���������
// ��. ������: ���������, �������� ���
void set_CatalogRecord_aud_hours(CatalogRecord* structure, int AudHours)
	{
	structure->AudHours = AudHours;
	}

//---------------------------------------------------------------------
// ������� ����������� ������ ������������ ��������� � ���������
// ��. ������: ���������, �������� ���
void set_CatalogRecord_fullname(CatalogRecord* structure, char* FullName)
	{
	structure->FullName = (char*)realloc(structure->FullName, (strlen(FullName) + 1) * sizeof(char));
	strcpy(structure->FullName, FullName);
	}

//---------------------------------------------------------------------
// ������� ����� ������ Catalog.txt �� ����� � ����������� �� �������� ��������������� �����
// ��. ������: ������, ������� ����� ��������
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
// ������� ����������� ������ ��������� CatalogRecord
void delete_CatalogRecord(CatalogRecord* structure)
	{
	free(structure->ShortName);
	free(structure->FullName);
	free(structure);
	}
