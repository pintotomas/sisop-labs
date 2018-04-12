#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    /*
    stat0
    Muestra el nombre, tipo y tamaño en bytes de un archivo regular o directorio.
    */

    if (argc != 2){
        printf("Uso: <./stat0 archivo_o_carpeta_existente_con_permisos_de_lectura>\n");

        return 1;
    }

    char *file_name = argv[1];
    struct stat buf;
    int status = stat(file_name, &buf);
    if (status == -1){
        printf("Error al consultar por las estadisticas\n");
        return 1;
        }

    printf("File Size: %ld bytes\n",buf.st_size);
    printf("File name: %s\n",file_name);
    printf("Type: %s\n", (S_ISREG(buf.st_mode)) ? "Regular file" : "Folder");
    return 0;
}
