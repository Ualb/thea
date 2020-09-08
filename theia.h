#ifndef theia_h
#define theia_h

#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include "utility/utility.h"

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
 * tipos de datos aceptados
 */
enum data_types {
    INT,
    CHAR,
    CHAR_LEN,
    BOOLEAN,
    TEXT,
    DOUBLE,
    BYTE
};

/**
 * caracteristicas unicas de cada hoja
 */
typedef struct {
    unsigned int identity;
    char *name;
    enum data_types type;
    boolean isNull;
    boolean isPrimary;
//    condicion
} fields;

/**
 * tipos de datos en cada elemento de la hoja
 */
struct sheet_data {
    fields *fields;
    int size_fields;
};

/**
 * otros datos de una hoja
 */
struct sheet_meta_data {
    int *this_memory_location;
    int *id_selected; // identity campo
    int *seek_next_sheet;
    int *numbers_of_rows;
    int *seek_first_data;
};

/**
 * The sheets are the abstract entities for the datas
 */
struct sheet {
    const char *name;
    struct sheet_data sheet_data;
    struct sheet_meta_data sheet_meta_data;
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
struct response *add(char *sheet, char *line);

/**
* crear una nueva hoja de datos
*/
struct response *create(char *sheet);

/**
 * editar filas, con la condicion especificada (opcional)
 */ 
struct response *edit(char *sheet, char *condition);

/**
 * remover lineas, con la condicion especificada
 */
struct response *remove_line(char *sheet, char *condition);

/**
 * eliminar hoja de datos
 */
struct response *del(char *sheet);

/**
 * leer lineas de la hoja de datos con la condicion especificada
 */
struct line *read(char *sheet, char *condition);
#endif