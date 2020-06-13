#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "theia.h"

int main (void)
{ 
    char *sheet = (char *) malloc(50);
    sheet = "[[idEmployee, int, id],[name, varchar(45)]]{seek of memory, 0, null, 0, null}";
    char *tok = tokenizer(sheet);
    printf("%s", tok);
    return 0;
}