#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "theia.h"

#define READ_FILE 0
#define WRITE_FILE 1

struct doc
{
    FILE *file;
    char *path;
};

//documento de la base de datos
struct doc *doc;

// obtiene el acceso al cuaderno maestro
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

struct response *create(char *sheet) {
    struct structure *datas = capture_structure(sheet);
} 