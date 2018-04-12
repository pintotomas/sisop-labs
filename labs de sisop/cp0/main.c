#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024
int main(int argc, char **argv)
{

    /*
    cp0
    copia los contenidos de un archivo a otro. 
    */

    char buffer[BUFSIZE];
    int length;
    int fd, fd_destino;
    char *file_origen = argv[1];
    char *file_destino = argv[2];
    fd_destino = open(file_destino,O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    fd = open(file_origen, O_RDONLY); //El original existe
    if ((fd < 0) | (fd_destino < 0)){
        return 1;
        }

    length = read(fd, buffer, BUFSIZE);
    while (length > 0){
        write(fd_destino, buffer, length);
        length = read(fd, buffer, BUFSIZE);
    }
    close(fd);
    close(fd_destino);
    return 0;
}
