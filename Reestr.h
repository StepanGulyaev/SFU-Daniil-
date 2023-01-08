#ifndef REESTR_H
#define REESTR_H

#include "ReestrRecord.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Reestr
	{
	ReestrRecord** reestr;
	size_t length;
	} Reestr;

Reestr* create_Reestr();
void init_Reestr(FILE* file, Reestr* structure);
void add_ReestrRecord(Reestr* structure, ReestrRecord*);
void delete_Reestr(Reestr* structure);

#endif