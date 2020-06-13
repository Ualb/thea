#ifndef theia_h
#define theia_h

#include <stdlib.h> 
#include <string.h>
#include <stdio.h>

/**
 * The document is a collections of informations
 * required for the file .db 
 */
struct document {
    unsigned int *numbers_of_sheet;
    unsigned int *first_sheet;
};

/**
 * A line is a row of the sheet
 */
struct line {
    const char *structure;
    unsigned int *this_memory_location;
    unsigned int *next_row;
};

/**
 * The sheets are the abstract entities for the datas
 */
struct sheet {
    const char *name;
    const char *structure; 
    unsigned int *this_memory_location;
    unsigned int *id_selected;
    unsigned int *next_sheet;
    unsigned int *numbers_of_data;
    unsigned int *first_row;
};

/**
 * A response is a structure for funtions what 
 * do not return lines or sheets
 */
struct response {
    unsigned int *is_ok;
    unsigned int *id_line;
    unsigned int *error;
};

/**
 *  agrega una linea nueva a la hora especificada
 */
struct response *add(char *sheet, char *line) {};

/**
* crear una nueva hoja de datos
*/
struct response *create(char *sheet) {}; 

/**
 * editar filas, con la condicion especificada
 */ 
struct response *edit(char *sheet, char *condition) {};

/**
 * editar hoja de datos
 */ 
struct response *edit(char *sheet) {};

/**
 * remover lineas, con la condicion especificada
 */
struct response *remove(char *sheet, char *condition) {};

/**
 * eliminar hoja de datos
 */
struct response *del(char *sheet) {};

/**
 * leer lineas de la hoja de datos con la condicion especificada
 */
struct line *read(char *sheet, char *condition);


// define un entero iterable, para for, while y demas
typedef unsigned int iterator;




// test zone

char *tokenizer(char *sheet){};


#endif