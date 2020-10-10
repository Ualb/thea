#include "panic.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


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
        case EACCES:
            printf("ERROR [EACCES] 1002 - Permiso denegado al crear el archivo\n");
            break;
        case ENAMETOOLONG:
            printf("ERROR [ENAMETOOLONG] 1002 - La direccion excede los PATH_MAX o NAME_MAX del sistema\n");
            break;
        case ENOENT:
            printf("ERROR [ENOENT] 1002 - Falto un directorio en la direccion\n");
            break;
        case ENOTDIR:
            printf("ERROR [ENOTDIR] 1002 - El nombre del directorio no existe\n");
            break;
        case EMFILE:
            printf("ERROR [EMFILE] 1002 - El archivo tiene una llamada, no se puede acceder a el\n");
            break;
        case ENFILE:
            printf("ERROR [ENFILE] 1002 - Demasiados archivos abiertos en el sistema\n");
            break;
        default:
            break;
    }
}