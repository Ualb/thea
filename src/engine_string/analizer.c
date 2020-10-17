#include <malloc.h>
#include <string.h>

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

// return the slice string by str with start and end characters
char *substractSText(char* str, char* start, char* end) {
//    invalid str
    if (strlen(str) <= strlen(start) + strlen(end)) return str;
    if (strlen(start) > 1 || strlen(end) > 1) return str;
//    the start char exists in str
    int startPosition, endPosition;
    for (iterator i = 0; i < strlen(str); ++i) {
        if (str[i] == start[0]) startPosition = i;
        if (str[i] == end[0]) endPosition = i;
    }
    if (startPosition > endPosition) return str;
    return substractText(str, startPosition, endPosition);
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

// response true or false by the question start with?
boolean startWith(char* str, const char* prefix) {
//    delted all spaces
    char *withoutSpaces = removeSpaces(str);
    for (iterator i = 0; i < strlen(prefix); ++i)
        if (prefix[i] != withoutSpaces[i])
            return False;
    return True;
}


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