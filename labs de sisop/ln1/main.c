#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int link(const char *oldpath, const char *newpath);
#include <fcntl.h>           /* Definition of AT_* constants */


int main(int argc, char** argv)
{
    /*
     ln1
     Crea hard links
    */
    char *target = argv[1];
    char *linkpath = argv[2];
    int success = link(target, linkpath);
    if (success != 0){
        return 1;
        }
    return 0;
}
