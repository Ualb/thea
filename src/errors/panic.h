

#ifndef THEIA_PANIC_H
#define THEIA_PANIC_H

#define FILE_DATABASE_ERROR             1000
#define FLOW_TO_DATABASE_NO_CLOSE       1001
#define PARSE_LEN_QUERY                 1002
#define NOT_FILE_CURRENT_ERROR          1003


typedef unsigned int iterator;
void panic(unsigned int error, ...);

#endif THEIA_PANIC_H