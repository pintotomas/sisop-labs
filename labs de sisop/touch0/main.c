#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char **argv)
{

    /*
	touch0/touch1
    Toma como parámetro un archivo y lo crea en caso de que no exista (En blanco). Si el archivo ya existía, se modifica su fecha de acceso y de modificacion a la hora actual.
    */
    if (argc != 2){
        printf("Uso: <./touch0 nombre_archivo_a_crear>\n BOBO");
        return 1;
    }

    char* file_name = argv[1];
    int fd = open(file_name,O_CREAT|O_RDONLY, S_IRUSR|S_IWUSR);
    if (fd < 0){
        printf("Error al crear\n");
    }

    struct timeval *times;
    gettimeofday(times, NULL);
//touch1, con utimes y futimes, lo que cambia es que en uno se utiliza el file descriptor y en el otro el nombre del archivo directamente.
    int success = utimes(file_name, times);
//    int success = futimes(fd, times);
    if (success != 0){
        perror("");
    }
    close(fd);
    return 0;
}
