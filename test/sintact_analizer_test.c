#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../analizer/analizer.h"
#include "../utility/utility.h"

boolean test_subtract_text();
boolean test_remove_end_spaces();
boolean test_remove_spaces();

boolean main(void) {
    printf("%s", test_subtract_text()? "." : "F");
    printf("%s", test_remove_end_spaces()? "." : "F");
    printf("%s", test_remove_spaces()? "." : "F");
    return EXIT_SUCCESS;
}

boolean test_subtract_text() {
    char *text = "hola mundo cruel";
    char *data = substract_text(text, 5, (int) (strlen(text)));
    if(strcasecmp(data, "mundo cruel") == 0) return True;
    return False;
}

boolean test_remove_end_spaces() {
    char *text = "esto   ";
    char *data = remove_end_spaces(text);
    if(strcasecmp(data, "esto") == 0) return True;
    return False;
}

boolean test_remove_spaces() {
    char *text = "h o l a";
    char *data = remove_spaces(text);
    if(strcasecmp(data, "hola") == 0) return True;
    return False;
}