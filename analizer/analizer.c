#include <malloc.h>
#include <string.h>

#include "../utility/utility.h"
#include "analizer.h"

// Sustrae una procion de un texto
char *substract_text(char *str, int start, int end) {
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
char *remove_end_spaces(char *str) {
    iterator len = strlen(str);
    if (len > 0) {
        iterator end = len - 1;
        while (str[end] == ' ') --end;
        return substract_text(str, ZERO_VALUE, end);
    }
    return str;
}

// El algoritmo elimina los espacios dentro de una cadena de texto
char *remove_spaces(char *str) {
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