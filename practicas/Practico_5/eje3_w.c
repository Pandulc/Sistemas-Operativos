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

    int fd, wr;
    char buff[MAXP];
    time_t time1 = time(NULL);

    fd = open("peje3", O_WRONLY);

    if(fd < 0){
        printf("No pude acceder a la pipe \n");
        return 1;
    }
    sprintf(buff, "%s", ctime(&time1));
    wr = write(fd, buff, MAXP);

    if(wr < 0){
        printf("No pude escribir por el pipe \n");
    }

    return 0;
}

