#include "iofile.h"
#include "../constants.h"
#include "../errors/panic.h"
#include "../engine_string/analizer.h"

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

boolean okStreamFile(const char* location);
boolean createControlDOC(const char* name);
boolean updateControlDOC(const char* name);
boolean fileExist(FILE *file);
char* getCurrentPath(void);

boolean createDOC(const char* name, const char* location) {
//    first check the location
    if (okStreamFile(location)) {
//        the create a file functionality
        FILE *file = fopen(location, "rb+");
        if (file == NULL) return False;
//        search the file if exists
        if (!fileExist(file))
//        not exists
            return createControlDOC(name);
        return updateControlDOC(name);
    }

    return False;
}

/**
 * The algoritm creates a file in the current path with the name
 * '.equifinality' and intoduce the dir of the docs created's.
 * @param struct of FILE
 * @return Success (True) or fairlure (False)
 */
boolean createControlDOC(const char* name) {
    char *path = getCurrentPath();
    FILE *file = fopen(strcat(path, name), "r");
    if (file == NULL) return False;
//    write datas in the file

    return True;
}

/**
 * The algoritm updates a file in the current path with the name
 * '.equifinality', see @relatesalso 'createControlDOC'.
 * @param struct of FILE
 * @return Success (True) or fairlure (False)
 */
boolean updateControlDOC(const char* name) {
    return True;
}

/**
 * Check so the dir of the DOC is input/output ok.
 * @param location Dir to check
 * @return Success (True) or fairlure (False)
 */
boolean okStreamFile(const char* location) {
    DIR *dir;
    dir = opendir(location);
    if (dir) {
        closedir(dir);
        return True;
    } else {
        panic(errno);
    }

    return False;
}

boolean fileExist(FILE *file) {
    return True;
}

/**
 *
 * @return
 */
char* getCurrentPath(void) {
    FILE *file = fopen("./current.txt", "r");
    if (file == NULL) panic(errno);
    char *buffer[150];
    while(feof(file) == 0) {
        fgets(*buffer, 150, file);
        if (startWith(buffer, "CURRENT_PATH") == True) return substractSText(*buffer, "\"", "\"");
    }

    return "";
}