#include <stdio.h>
#include <stdlib.h>
int rename(const char *oldpath, const char *newpath);
#include <fcntl.h>           /* Definition of AT_* constants */
#include <string.h>
char * strtok ( char * str, const char * delimiters );
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int stat(const char *pathname, struct stat *buf);

int is_directory(char *pathname){


    char * my_copy;
    my_copy = malloc(sizeof(char) * (strlen(pathname) + 1));
    strcpy(my_copy,pathname);

    struct stat sb;
    char *slash = "/";
    char *path = strtok(my_copy, slash);
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        return 0;
    }

    return 1;

}

int countChars( char* s, char c )
{
    return *s == '\0'
              ? 0
              : countChars( s + 1, c ) + (*s == c);
}

int main(int argc, char **argv)
{
    /*mv0
    permite mover un archivo de un directorio a otro.
    */
    char *oldpath = argv[1];
    char *newpath = argv[2];
    char * my_copy;
    my_copy = malloc(sizeof(char) * (strlen(newpath) + 1));
    strcpy(my_copy,newpath);
    int cantidad_slashes = countChars(my_copy, '/');
    //Verifico que si se quiere mover a otro directoriom exista
    if (cantidad_slashes > 0){
        if (is_directory(newpath) != 0){
            printf("El directorio destino no existe\n");
            return 1;
        }
    }
    int success = rename(oldpath, newpath);
    if (success != 0){

        printf("Hubo un error al momento de mover");
        return 1;

    }
    return 0;
}
