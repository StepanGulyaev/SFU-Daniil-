//#define DEBUG

#ifdef DEBUG
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "CatalogRecord.h"
#include "ReestrRecord.h"
#include "TableRecord.h"
#include "Catalog.h"
#include "Reestr.h"
#include "Table.h"
#include "Input.h"
#include "Output.h"
#include <assert.h>

int main()  
    {

    FILE* finCatalog = fopen("Catalog.txt", "r");
    FILE* finReestr = fopen("Reestr.txt", "r");
    FILE* fin = fopen("input.txt", "r");

    #ifdef DEBUG
    assert(finCatalog);
    assert(finReestr);
    assert(fin);
    #endif

   
    if (check_file(finCatalog) && check_file(finReestr) && check_file(fin))
        {
        Catalog* catalog = create_Catalog();
        init_Catalog(finCatalog, catalog);

        Reestr* reestr = create_Reestr();
        init_Reestr(finReestr, reestr);

        Input* input = create_Input();
        init_Input(fin, input);

        Output* output = create_Output();
        init_Output(catalog, reestr, input, output);
        print_Output(output);

        delete_Catalog(catalog);
        delete_Reestr(reestr);
        delete_Input(input);
        delete_Output(output);

        fclose(finCatalog);
        fclose(finReestr);
        fclose(fin);
        }
    else
        {
        printf("Required files don't exist.\n");
        exit(1);
        }

    #ifdef DEBUG
    _CrtDumpMemoryLeaks();
    #endif
	return 0;
    }

