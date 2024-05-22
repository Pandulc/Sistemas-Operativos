#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXP 25

int main (int argc, char *argv[]){

    int fd, rd;
    char buff[MAXP];

    fd = open("peje3", O_RDONLY);

    if(fd < 0){
        printf("No pude acceder a la pipe \n");
        return 1;
    }

    rd = read(fd, buff, MAXP);

    if(rd < 0){
        printf("No pude escribir por el pipe \n");
    }

    printf("La fecha es: %s", buff);

    return 0;
}
