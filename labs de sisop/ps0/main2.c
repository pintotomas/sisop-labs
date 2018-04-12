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
        if (dirent_p->d_type == DT_DIR){
            char name = *dirent_p->d_name;
            printf(dirent_p->d_name);
           // if (isdigit(name)){
        //        printf("%d\n",name);
              /*  DIR *pid_dirr = opendir(dirent_p->d_name);
                if (pid_dirr){
                struct dirent *dirent_p2 = readdir(pid_dirr);

                printf("TODO BIEN");
                }
                else{
                printf(name);}
                /*

      /*          char *curr_name = dirent_p2->d_name;
                char *compare = "stat";
                while (dirent_p2){

                    if (strcmp(curr_name, compare ) == 0){
                        printf("Se encontro!");
                    }
                    dirent_p2 = readdir(pid_dirr);
                }
                //FILE *fp = fopen("stat","r");
                //if( fp == NULL){
                //printf("ERROR");}*/
//                closedir(pid_dirr);
            }
        }
        dirent_p = readdir(directorio);
    }
    closedir(directorio);
    return 0;
}
