#include <malloc.h>
#include <mem.h>

#include "../utility/utility.h"
#include "analizer.h"

// Sustrae una procion de un texto
char *substract_text(char *str, int start, int end) {
    if (end > start) return str;
    int len = (end - start) + 1;
    char *response = (char *) malloc(len);
    while (start < end) {
        response[start] = str[start];
        ++start;
    }
    response[end + 1] = '\0';
    return response;
}


// Elimina los espacios encontrados al final de un texto
char *remove_end_spaces(char *str) {
    size_t len = strlen(str);
    if (len > 0) {
        iterator end = len - 1;
        while (str[end] == ' ') --end;
        return substract_text(str, ZERO_VALUE, end);
    }
    return str;
}

// El algoritmo elimina los espacios dentro de una cadena de texto
char *remove_spaces(char *str) {
    size_t len = strlen(str);
    if (len > 0) {
        iterator i = 0;
        iterator y = 0;
        char *response = (char *) malloc(len);
        while (str[i] != '\0') {
            if (str[i] == ' ') response[y++];
            ++i;
        }
        return response;
    }
    return str;
}