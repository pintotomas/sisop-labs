#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
int unlink(const char *pathname);
#include <fcntl.h>           /* Definition of AT_* constants */

#include <errno.h> //Para rm1
#include <string.h>
int main(int argc, char **argv)
{
    /*
    rm0/rm1
    Elimina un archivo regular.
    Si se intenta eliminar un directorio se notifica que no es posible.
    */
    if (argc != 2){
        printf("Uso: <./rm0 archivo_regular_existente>\n");
        return 1;
    }
    char* file_name = argv[1];
    int success = unlink(file_name);
    if (success != 0){
        //rm1
        if (errno == EISDIR){
            fprintf(stderr, "Error! cannot remove: %s",file_name);
            perror(":");
            }
        }
    return 0;
}
