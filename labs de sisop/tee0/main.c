#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFSIZE 1024
int main(int argc, char **argv)
{

    /*
    tee0
    Toma como parámetro un archivo, y escribe todo lo que llega por entrada estándar, tanto en la salida estándar como al archivo.
    Por defecto tee crea el archivo si no lo encuentra, y lo sobreescribe (trunca) si ya existía.
    */
    if (argc != 2){
        printf("Uso: ./tee0 <arch>\n");
    }
    char buffer[BUFSIZE];
    int length;
    int fd_destino;
    char *file_destino = argv[1];
    fd_destino = open(file_destino,O_CREAT|O_TRUNC|O_WRONLY, S_IRUSR|S_IWUSR);
    if (fd_destino < 0){
        return 1;
        }

    length = read(0, buffer, BUFSIZE); //LEO DE LA ENTRADA ESTANDAR
    while (length > 0){
        //Escribo en stdout y en el archivo
        write(fd_destino, buffer, length);
        write(1, buffer, length);
        length = read(0, buffer, BUFSIZE);
    }
    close(fd_destino);
    return 0;
}
