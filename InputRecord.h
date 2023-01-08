#ifndef INPUTRECORD_H
#define INPUTRECORD_H

typedef struct InputRecord
	{
	char* Keyword;
	char* FamilyIO;
	char* Month;
	char* Year;
	} InputRecord;

InputRecord* create_InputRecord();
void init_InputRecord(InputRecord* structure, char* str);
char* get_InputRecord_keyword(InputRecord* structure);
char* get_InputRecord_familyio(InputRecord* structure);
char* get_InputRecord_month(InputRecord* structure);
char* get_InputRecord_year(InputRecord* structure);
void set_InputRecord_keyword(InputRecord* structure);
void set_InputRecord_familyio(InputRecord* structure, char* ShortName);
void set_InputRecord_month(InputRecord* structure, char* ShortName);
void set_InputRecord_year(InputRecord* structure, char* ShortName);
char** separate_InputRecord_string(char* str);
void delete_InputRecord(InputRecord* structure);

#endif
