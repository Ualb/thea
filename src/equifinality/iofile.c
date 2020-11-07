#include "iofile.h"
#include "../constants.h"
#include "../errors/panic.h"
#include "../engine_string/analizer.h"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>


// enumerator process apply to .equifinality file
enum type_process_to_file {
    WRITE_IN_START,
    WRITE_IN_END
};

boolean okStreamFile(const char* location);
boolean createControlDOC(const char* name, char* dir);
boolean updateControlDOC(const char* name, char* dir);
boolean writeInEquifinality(FILE *file, char* dir);
FILE *equifinalityFile(const char* name, enum type_process_to_file kind);
boolean fileExist(void);
char* getCurrentPath(void);

boolean createDOC(const char* name, char* location) {
//    first check the location
    if (okStreamFile(location)) {
//        the create a file functionality (if exist???)
        FILE *file = fopen(strcat(location, name), "wb");
        if (file == NULL) {
            return False;
        }
//        close the file of DOC datas
        fclose(file);

        char *dir = (char *) malloc(sizeof(char) * (strlen(location) + strlen(name)));
        if (dir == NULL) {
            panic(errno);
            return False;
        }
//        .equifinality - search the file if not exists
        if (!fileExist()) {
//        not exists
            return createControlDOC(name, dir);
        }

        return updateControlDOC(name, dir);
    }

    return False;
}

/**
 * The algoritm creates a file in the current path with the name
 * '.equifinality' and intoduce the dir of the docs created's.
 *
 * @param struct of FILE
 * @return Success (True) or fairlure (False)
 */
boolean createControlDOC(const char* name, char* dir) {
    return writeInEquifinality(equifinalityFile(name, WRITE_IN_START), dir);
}

/**
 * The algoritm updates a file in the current path with the name
 * '.equifinality', see @relatesalso 'createControlDOC'.
 *
 * @param struct of FILE
 * @return Success (True) or fairlure (False)
 */
boolean updateControlDOC(const char* name, char* dir) {
    return writeInEquifinality(equifinalityFile(name, WRITE_IN_END), dir);
}

/**
 * Create to file and return FILE struct
 *
 * @param name
 * @return FILE struct
 */
FILE *equifinalityFile(const char* name, enum type_process_to_file kind) {
    char *path = getCurrentPath();
    char *kindStr;
    kindStr = (kind == WRITE_IN_START)? "wb": "ab";
    FILE *file = fopen(strcat(path, name), kindStr);
    if (file == NULL) {
//        validate the error valua
        free(kindStr);
        return False;
    }

    return file;
}

/**
 *
 * @return
 */
boolean writeInEquifinality(FILE *file, char* dir) {
    boolean rtn = (fwrite(dir, 1, sizeof(dir), file) > 0)? True: False;
    fclose(file);
    free(dir);
    return rtn;
}

/**
 * Check so the dir of the DOC is input/output ok.
 *
 * @param location Dir to check
 * @return Success (True) or fairlure (False)
 */
boolean okStreamFile(const char* location) {
    DIR *dir;
    dir = opendir(location);
    if (dir) {
        closedir(dir);
        return True;
    } else panic(errno);

    return False;
}

/**
 * Response to question if the file .equifinality in really exists
 *
 * @return an bollean with the value True or False
 */
boolean fileExist(void) {
    char *path = getCurrentPath();
    char *e = "\\.equifinality";
    FILE *file = fopen(strcat(path, e), "r");
    if (file != NULL) {
        fclose(file);
        return True;
    }

    return False;
}

/**
 * Obtains the current path of the current.txt
 *
 * @return PATH in char*
 */
char* getCurrentPath(void) {
    FILE *file = fopen("./current.txt", "r");
    if (file == NULL) panic(errno);
    char buffer[150];
    while(feof(file) == 0) {
        fgets(buffer, 150, file);
        if (startWith(buffer, "CURRENT_PATH") == True) {
            fclose(file);
            return substractSText(buffer, "\"", "\"");
        }
    }

    return "";
}