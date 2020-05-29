#include <stdlib.h> 
#include <string.h>

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
 *  agrega una linea nueva a la hora especificada
 */
struct response *add(char *sheet, char *line) {}

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

struct structure {
    const char *type;
    const char *name;
    const unsigned int *is_identifier;
    struct structure *next;
};

// numero de corchetes de apertura
#define TWO_CORCHETTE_APPERT    2
#define ONE_SEMICOLON           1
#define TWO_SEMICOLONS          2 

// define un entero iterable, para for, while y demas
typedef unsigned int iterator;

// extrae de una cadena de texto, las columnas y sus tipos de datos
inline struct structure *capture_structure(char *sheet) //ERROR, BUSCAR COMO RETORNAR UNA COLECCION DE STRUCTURAS
{
    struct structure new_sheet;
    unsigned int *counter_corchette_open = (unsigned int *) malloc(sizeof(unsigned int));
    unsigned int *counter_corchette_close = (unsigned int *) malloc(sizeof(unsigned int));
    unsigned int *pointer_of_corchette = (unsigned int *) malloc(sizeof(unsigned int));
    for (iterator index = 0; index < strlen(sheet); ++index) 
    {
        if(sheet[index] == '[') 
        {
            ++counter_corchette_open;
            pointer_of_corchette = index;
            
        } else if(sheet[index] == ']')
        {
            ++counter_corchette_close;
        } 
        if (counter_corchette_close != 0 && counter_corchette_open - counter_corchette_close == 1) 
        {
            char *letters = (char *) malloc(sizeof(char) * index - *pointer_of_corchette - 1);
            for (iterator i = 0; i < index - *pointer_of_corchette - 1; i++)
            {
                letters[i] = sheet[*pointer_of_corchette - 1 + i];
            }
            char *token = strtok(letters, ',');
            iterator semicolon_counter = 0;
            while (token != NULL) {
                if (semicolon_counter == ONE_SEMICOLON) new_sheet.name = token;
                else if (semicolon_counter == TWO_SEMICOLONS) new_sheet.type = token;
                else new_sheet.is_identifier = 1;
                token = strtok(NULL, ',');
            }
            counter_corchette_open = 1;
            counter_corchette_close = 0;   
        }
        
    }
}

#define FILE_DATABASE_ERROR             1000
#define FLOW_TO_DATABASE_NO_CLOSE       1001

inline void panic(unsigned int error, ...)
{
    switch (error)
    {
        case FILE_DATABASE_ERROR:
            printf("ERROR [FILE_DATABASE_ERROR] 1000 - Error al acceder al fichero maestro\n"); 
            exit(0);
            break;
        case FLOW_TO_DATABASE_NO_CLOSE:
            printf("ERROR [FLOW_TO_DATABASE_NO_CLOSE] 1001 - No se puede cerrar la base de datos\n");
            break;
        default:
            break;
    }
}