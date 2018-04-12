#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);


int main(int argc, char** argv)
{

    if (argc != 2){
        printf("Uso: ./tee0 <arch>\n");
        return 1;
    }
    char *nombre_directorio;
    nombre_directorio =argv[1];
    DIR *directorio = opendir(nombre_directorio);
    struct dirent *dirent_p = readdir(directorio);
    while(dirent_p){
        if (dirent_p->d_type == DT_REG){
            printf("%s\n", dirent_p->d_name);
        }
        dirent_p = readdir(directorio);
    }
    closedir(directorio);
    return 0;
}
