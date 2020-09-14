

#ifndef THEIA_UTILITY_H
#define THEIA_UTILITY_H


#define True 1
#define False 0

typedef int boolean;

#define FILE_DATABASE_ERROR             1000
#define FLOW_TO_DATABASE_NO_CLOSE       1001
#define PARSE_LEN_QUERY                 1002


typedef unsigned int iterator;
void panic(unsigned int error, ...);

#endif THEIA_UTILITY_H