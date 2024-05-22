#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>


int main(int argc, char *argv[]) {

    DIR *odir = opendir("/");
    struct dirent *rt;

    if (odir < 0) {
        printf("No se puede abrir el directorio \n");
        return odir;
    }

    while (rt = readdir(odir)) {
        printf("%s \n", rt->d_name);
    }

    return 0;
}
