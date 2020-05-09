#include <stdio.h>


struct doc
{
    FILE *file;
};

struct doc *get_doc(char *path) 
{
    FILE *file = fopen(path, "a+b");
    if (file == NULL) return NULL;
    struct doc *doc;
    doc->file = file;
    return doc;
}