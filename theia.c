
#include <stdbool.h>
#include <string.h>

#include "theia.h"
#include "utility/utility.h"


struct doc *doc;

#define ZERO_VALUE 0

#define READ_FILE 0
#define WRITE_FILE 1


/**
 * Zona de estruturas
 */
struct doc
{
    FILE *file;
    char *path;
};


struct doc *get_doc(char *path, unsigned int kind) 
{
    char *restric = NULL; 
    if (kind == READ_FILE) restric = "rb";      //seek al inicio
    else restric = "ab";                        // seek al final
    FILE *file = fopen(path, restric);
    if (file == NULL) panic(FILE_DATABASE_ERROR);
    doc->file = file;
    doc->path = path;
    return doc;
}

bool close_doc() 
{
    if (doc->file != NULL) fclose(doc->file); 
    else 
    {
        panic(FLOW_TO_DATABASE_NO_CLOSE);
        return false;
    }
    return true;
}

char *sheet_structure   = NULL;
char *meta_shhet        = NULL;

struct sheet *capture_sheet(char *sheet) 
{
    struct sheet result;
    int toknum = 0;
    char data = sheet;
    const char delimiters[] = "[ , ]{ }";
    char *token = strtok(data, delimiters);
    while (token != NULL)
    {
        ++token;
        if (toknum == 0) result.name = token;
        token = strtok(NULL, delimiters);
    }
    return &result;
}
