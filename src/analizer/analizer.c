#include <malloc.h>
#include <string.h>

#include "../utility/utility.h"
#include "analizer.h"
#include "../theia.h"

// Sustrae una procion de un texto
char *substractText(char *str, int start, int end) {
    if (start > end) return str;
    unsigned int len = (end - start);
    char *response = (char *) malloc(len * sizeof(char));
    int counter = 0;
    while (start < end + 1) {
        response[counter++] = str[start++];
    }
    response[end + 1] = '\0';
    return response;
}


// Elimina los espacios encontrados al final de un texto
char *removeEndSpaces(char *str) {
    iterator len = strlen(str);
    if (len > 0) {
        iterator end = len - 1;
        while (str[end] == ' ') --end;
        return substractText(str, ZERO_VALUE, end);
    }
    return str;
}

// El algoritmo elimina los espacios dentro de una cadena de texto
char *removeSpaces(char *str) {
    iterator len = strlen(str);
    if (len > 0) {
        iterator i = 0;
        iterator y = 0;
        char *response = (char *) malloc(len * sizeof(char));
        while (i < len + 1) {
            if (str[i] != ' ') response[y++] = str[i];
            ++i;
        }
        response[len + 1] = '\0';
        return response;
    }
    return str;
}

// el algoritmo se encarga de rebanar una hoja de datos


//  token data tiene como fin rebanar un texto y extraer sus componentes dado en un {}
struct sheet *captureSheet(char *sheet_definition) {
    struct sheet result;
    int toknum = 0;
    const char delimiters[] = "[ , ]{ }";
    char *token = strtok(sheet_definition, delimiters);
    while (token != NULL) {
        ++token;
        if (toknum == 0) result.name = token;
        token = strtok(NULL, delimiters);
    }
    return &result;
}