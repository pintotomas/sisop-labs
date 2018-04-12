
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]){

    /* cp1.c

    Copia los contenidos de un archivo a otro, usando mappings de memoria

    Uso: ./cp1 source-file dest-file

*/

    char *src, *dst;
    int fdSrc, fdDst;
    struct stat sb;

    if (argc != 3){
        printf("Uso: ./cp1 arch_origen arch_destino\n");
    }
    fdSrc = open(argv[1], O_RDONLY);
    if (fdSrc == -1){
        printf("Error al abrir el archivo origen para lectura\n");
        return 1;
    }

    /* Obtengo el tamaño del archivo origen*/

    if (fstat(fdSrc, &sb) == -1){
        printf("Error al acceder a la metadata del archivo origen\n");
        return 1;
    }
    /* Si el tamaño es 0, termino el programa, mmap tiraria error EINVAL */

    if (sb.st_size == 0){
        fdDst = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        close(fdDst);
        return 0;
    }

    src = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fdSrc, 0);
    if (src == MAP_FAILED){
        printf("No se pudo reservar memoria en el address space para el archivo origen\n");
        return 1;
    }

    fdDst = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fdDst == -1){
        printf("No se pudo crear/abrir el archivo destino\n");
        return 1;
    }

    if (ftruncate(fdDst, sb.st_size) == -1){
        printf("No se pudo truncar el tamaño del archivo destino\n");
        return 1;
    }

    dst = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdDst, 0);
    if (dst == MAP_FAILED){
        printf("No se pudo reservar memoria en el address space para el archivo destino\n");
        return 1;
    }

    memcpy(dst, src, sb.st_size);       /* Copio los bytes del origen al destino */
    close(fdDst);
    close(fdSrc);
}
