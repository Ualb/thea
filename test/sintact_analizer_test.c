#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/engine_string//analizer.h"
#include "../src/errors/panic.h"

boolean testSubtractText();
boolean testRemoveEndSpaces();
boolean testRemoveSpaces();

int main(void) {
    printf("%s", testSubtractText() ? "." : "F");
    printf("%s", testRemoveEndSpaces() ? "." : "F");
    printf("%s", testRemoveSpaces() ? "." : "F");
    return EXIT_SUCCESS;
}

boolean testSubtractText() {
    char *text = "hola mundo cruel";
    char *data = substractText(text, 5, (int) (strlen(text)));
    if(strcasecmp(data, "mundo cruel") == 0) return True;
    return False;
}

boolean testRemoveEndSpaces() {
    char *text = "esto   ";
    char *data = removeEndSpaces(text);
    if(strcasecmp(data, "esto") == 0) return True;
    return False;
}

boolean testRemoveSpaces() {
    char *text = "h o l a";
    char *data = removeSpaces(text);
    if(strcasecmp(data, "hola") == 0) return True;
    return False;
}