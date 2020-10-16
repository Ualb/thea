

#ifndef THEIA_ANALIZER_H
#define THEIA_ANALIZER_H
#define ZERO_VALUE 0

/**
 *
 * @param str
 * @param start
 * @param end
 * @return
 */
char *substractText(char *str, int start, int end);

/**
 *
 * @param str
 * @return
 */
char *removeEndSpaces(char *str);

/**
 *
 * @param str
 * @return
 */
char *removeSpaces(char *str);

/**
 *
 * @param str
 * @param preffix
 * @return
 */
bool startWith(char* str, char* preffix);

/**
 *
 * @param str
 * @param start
 * @param end
 * @return
 */
char *substractSText(char* str, char* start, char* end);

#endif THEIA_ANALIZER_H
