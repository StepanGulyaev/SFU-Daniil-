#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------------------
// ‘ункци€ считывает содержимое файла
// ¬х. данные: файл
char* fread_string(FILE* file) 
    {
    char* string = (char*)calloc(1, sizeof(char));
    size_t length = 1;
    string[0] = '\0';
    while (1)
        {
        char symbol = fgetc(file);
        if (symbol == '\n')
            {
            break;
            }
        length++;
        string = (char*)realloc(string, length * sizeof(char));
        string[length - 1] = '\0';
        string[length - 2] = symbol;
        }
    return string;
    }
//--------------------------------------------------

//--------------------------------------------------
// ‘ункци€ провер€ет, существует ли файл
// ¬х. данные: файл
int check_file(FILE* file)
    {
    if (file == NULL)
        {
        return 0;
        }
    return 1;
    }
//--------------------------------------------------

//--------------------------------------------------
// ‘ункци€ раздел€ет дату формата "MM.YYYY" на мес€ц и год
// ¬х. данные: дата 
char** separate_date(char* date)
    {
    char** info = (char**)calloc(2, sizeof(char*));
    char* month = strtok(date, ".");
    char* year = strtok(NULL, "");
    info[0] = (char*)calloc(strlen(month)+1, sizeof(char));
    info[1] = (char*)calloc(strlen(year)+1, sizeof(char));
    strcpy(info[0], month);
    strcpy(info[1], year);
    return info;
    }
//--------------------------------------------------