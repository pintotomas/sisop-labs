#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);

int main(int argc, char** argv)
{

    if (argc != 1){
        printf("Uso: ./ps0\n");
        return 1;
    }



    char *nombre_directorio;
    nombre_directorio = "/proc";
    DIR *directorio = opendir(nombre_directorio);
    if (directorio == NULL){
        printf("Error al abrir directorio\n");
        return 1;
    }
    struct dirent *dirent_p = readdir(directorio);
    while(dirent_p){
        if (isdigit(*dirent_p->d_name)){
            char statDir[120];
            char *nombre_subdirectorio = dirent_p->d_name;
            strcpy(statDir, nombre_directorio);
            strcat(statDir, "/");
            strcat(statDir, nombre_subdirectorio);
            strcat(statDir, "/stat");
            FILE *statfile = fopen(statDir, "r");
            if (statfile){
            //Muestro solo el id del proceso, el nombre, su estado y el id del padre. Aunque de esta forma se podria mostrar toda la informacion del proceso.
                char pid[10];
                char comm[1024];
                char state[1024];
                char ppid[1024];

                if(fscanf(statfile, "%s %s %s %s", pid, comm, state, ppid) != EOF) {
                    printf("Mostrando informacion del proceso con id: %s\n", pid);
                    printf("Nombre del ejecutable: %s\nEstado del proceso: %s\nID del padre: %s\n\n", comm, state, ppid);
            }
                fclose(statfile);
            }

        }
        dirent_p = readdir(directorio);
    }

}
