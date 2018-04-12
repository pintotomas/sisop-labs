#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024
#include <stdio.h>
int main(int argc, char **argv)
{
    /*
     cat0
     Toma un archivo regular y muestra su contenido por salida estándar.
     */

    if (argc != 2){
        printf("Uso: <./cat0 archivo_existente_con_permisos_de_lectura>\n");
        return 1;
    }
    char buffer[BUFSIZE];
    int length;
    int fd;
    char *file_name = argv[1];

    fd = open(file_name, O_RDONLY);
    if (fd < 0){
        printf("Error al abrir el archivo\n");
        return 1;
        }

    length = read(fd, buffer, BUFSIZE);
    while (length > 0){
        write(1, buffer, length);
        length = read(fd, buffer, BUFSIZE);
    }
    close(fd);
    return 0;
}
