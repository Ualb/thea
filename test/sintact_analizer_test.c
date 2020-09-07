#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../analizer/analizer.h"
#include "../utility/utility.h"

boolean test_subtract_text();

boolean main(void) {
    printf("%s", test_subtract_text()? "." : "F");
    return EXIT_SUCCESS;
}

boolean test_subtract_text() {
    char *text = "hola mundo cruel";
    char *data = substract_text(text, 5, (int) (strlen(text)));
    if(strcasecmp(data, "mundo cruel") == 0) {
        return True;
    }
    return False;
}