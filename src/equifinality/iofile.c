#include "iofile.h"
#include "../constants.h"
#include "../errors/panic.h"

#include <dirent.h>
#include <errno.h>

boolean fairlureStreamFile(const char* location);


boolean createDOC(const char* name, const char* location) {
//    first check the location
    if (fairlureStreamFile(location)) {
//        the create a file functionality
    }
    return True;
}

/**
 * The algoritm creates a file in the current path with the name
 * '.equifinality' and intoduce the dir of the docs created's.
 *
 */
boolean createControlDOC() {
    return True;
}

/**
 * The algoritm updates a file in the current path with the name
 * '.equifinality', see @relatesalso 'createControlDOC'.
 *
 */
boolean updateControlDOC() {
    return True;
}

/**
 * Check so the dir of the DOC is ok.
 * @param location Dir to check
 * @return Success or fairlure
 */
boolean fairlureStreamFile(const char* location) {
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