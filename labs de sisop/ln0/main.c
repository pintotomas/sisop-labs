#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int symlink(const char *target, const char *linkpath);
#include <fcntl.h>           /* Definition of AT_* constants */


int main(int argc, char** argv)
{

    /* ln0
       permite crear enlaces simbólicos.
    */
    char *target = argv[1];
    char *linkpath = argv[2];
    int success = symlink(target, linkpath);
    if (success != 0){
        return 1;
        }
    return 0;
}
