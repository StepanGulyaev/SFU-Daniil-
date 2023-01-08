#ifndef TABLERECORD_H
#define TABLERECORD_H

#include <stdio.h>

typedef struct TableRecord
	{
	char* FamilyIO;
	char* ShortName;
	int AudHours;
	} TableRecord;

TableRecord* create_TableRecord();
void init_TableRecord(TableRecord* structure, char* str);
char* get_TableRecord_shortname(TableRecord* structure);
char* get_TableRecord_shortname(TableRecord* structure);
int get_TableRecord_audhours(TableRecord* structure);
void set_TableRecord_familyio(TableRecord* structure, char* FamilyIO);
void set_TableRecord_shortname(TableRecord* structure, char* ShortName);
void set_TableRecord_audhours(TableRecord* structure, int AudHours);
char** separate_TableRecord_string(char* str);
void delete_TableRecord(TableRecord* structure);

#endif 
