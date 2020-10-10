#include <stdio.h>
#include <stdlib.h>
#include "panic.h"


/* error zone */
void panic(unsigned int error, ...)
{
    switch (error)
    {
        case FILE_DATABASE_ERROR:
            printf("ERROR [FILE_DATABASE_ERROR] 1000 - Error al acceder al fichero maestro\n");
            exit(0);
        case FLOW_TO_DATABASE_NO_CLOSE:
            printf("ERROR [FLOW_TO_DATABASE_NO_CLOSE] 1001 - No se puede cerrar la base de datos\n");
            break;
        case PARSE_LEN_QUERY:
            printf("ERROR [PARSE_LEN_QUERY] 1002 - La entrada por su longitud no es una consulta\n");
            break;
        default:
            break;
    }
}