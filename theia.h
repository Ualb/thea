struct document {
    unsigned int *numbers_of_sheet;
    unsigned int *first_sheet;
};

struct line {
    const char *structure;
    unsigned int *this_memory_location;
    unsigned int *next_row;
};

struct sheet {
    const char *name;
    const char *structure; 
    unsigned int *this_memory_location;
    unsigned int *id_selected;
    unsigned int *next_sheet;
    unsigned int *numbers_of_data;
    unsigned int *first_row;
};


struct response {
    unsigned int *is_ok;
    unsigned int *id_line;
    unsigned int *error;
};

/**
 *  
 */
struct response *add(char *line) {}

/**
* crear una nueva hoja de datos
*/
struct response *create(char *sheet) {} 

/**
 * editar filas, con la condicion especificada
 */ 
struct response *edit(char *sheet, char *condition) {}

/**
 * editar hoja de datos
 */ 
struct response *edit(char *sheet) {}

/**
 * remover lineas, con la condicion especificada
 */
struct response *remove(char *sheet, char *condition) {}

/**
 * eliminar hoja de datos
 */
struct response *del(char *sheet) {}

/**
 * leer lineas de la hoja de datos con la condicion especificada
 */
struct line *read(char *sheet, char *condition);