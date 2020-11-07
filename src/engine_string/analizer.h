#ifndef THEIA_ANALIZER_H
#define THEIA_ANALIZER_H

#include "../constants.h"

#define ZERO_VALUE 0

/**
 * Sustrad one slace of str
 *
 * @param str
 * @param start
 * @param end
 * @return pointer to new str
 */
char *substractText(char *str, int start, int end);

/**
 * Return the slice string by str with start and end characters
 *
 * @param str
 * @param start
 * @param end
 * @return pointer to new str
 */
char *substractSText(char* str, char* start, char* end);

/**
 * Remove the end spaces
 *
 * @param str
 * @return pointer to new str
 */
char *removeEndSpaces(char *str);

/**
 * Remove all spaces
 *
 * @param str
 * @return
 */
char *removeSpaces(char *str);

/**
 * Response true or false by the question start with?
 *
 * @param str
 * @param preffix
 * @return a boolean True or False
 */
boolean startWith(char* str, const char* prefix);


#endif THEIA_ANALIZER_H
