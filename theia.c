#include <stdio.h>
#include <stdlib.h>
#include "theia.h"


struct doc
{
    FILE *file;
};

// obtiene el acceso al cuaderno maestro
struct doc *get_doc(char *path) 
{
    FILE *file = fopen(path, "a+b");
    if (file == NULL) return NULL;
    struct doc *doc;
    doc->file = file;
    return doc;
}

struct response *create(char *sheet) {
    
} 