#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "theia.h"

#define READ_FILE 0
#define WRITE_FILE 1

#define FILE_DATABASE_ERROR             1000
#define FLOW_TO_DATABASE_NO_CLOSE       1001
#define PARSE_LEN_QUERY                 1002

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

struct sheet *capture_sheet(char *sheet) 
{
    struct sheet result;
    int toknum = 0;
    char data[] = sheet;
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

struct response *create(char *sheet) {
    struct sheet *data = capture_sheet(sheet);
} 

/* error zone */

inline void panic(unsigned int error, ...)
{
    switch (error)
    {
        case FILE_DATABASE_ERROR:
            printf("ERROR [FILE_DATABASE_ERROR] 1000 - Error al acceder al fichero maestro\n"); 
            exit(0);
            break;
        case FLOW_TO_DATABASE_NO_CLOSE:
            printf("ERROR [FLOW_TO_DATABASE_NO_CLOSE] 1001 - No se puede cerrar la base de datos\n");
            break;
        case PARSE_LEN_QUERY:
            printf("ERROR [PARSE_LEN_QUERY] 1002 - La entrada por su longitud no es una consulta\n");
            break;
        default:
            break;
    }
}