#include <malloc.h>
#include <string.h>

#include "analizer.h"

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

char *substractSText(char* str, char* start, char* end) {
//    invalid str
    if (strlen(str) <= strlen(start) + strlen(end)) return str;
    if (strlen(start) > 1 || strlen(end) > 1) return str;
//    the start char exists in str
    int startPosition, endPosition;
    boolean startDone, endDone;
    for (iterator i = 0; i < strlen(str); ++i) {
        if (str[i] == start[0] && startDone) {
            startPosition = i;
            startDone = True;
            continue;
        }
        if (str[i] == end[0] && endDone) {
            endPosition = i;
            endDone = True;
            continue;
        }
    }
    if (startPosition > endPosition) return str;
    return substractText(str, startPosition, endPosition);
}

char *removeEndSpaces(char *str) {
    iterator len = strlen(str);
    if (len > 0) {
        iterator end = len - 1;
        while (str[end] == ' ') --end;
        return substractText(str, ZERO_VALUE, end);
    }
    return str;
}

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

boolean startWith(char* str, const char* prefix) {
//    delted all spaces
    char *withoutSpaces = removeSpaces(str);
    for (iterator i = 0; i < strlen(prefix); ++i)
        if (prefix[i] != withoutSpaces[i])
            return False;
    return True;
}