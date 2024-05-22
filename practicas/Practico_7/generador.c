#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXP 5
#define MAX 11

int main (int argc, char* argv[]){
    int fd, wr, ti, tam, tex;
    char buff[2];
    char buff2[MAX];

    srand(time(NULL));

    fd = open("input.txt", O_CREAT | O_WRONLY, 0644);

    if(fd < 0){
        printf("No pude crear el archivo \n");
    }
    sprintf(buff, "%d\n", MAXP);
    wr = write(fd, buff, 2);
    if(wr < 0){
        printf("Error al escribir \n");
    }

    for (int i = 0; i < MAXP; ++i) {
        ti = (rand() % 20);
        tam = (rand() % 10) + 1;
        tex = (rand() % 20) + 20;
        sprintf(buff2,"%d\t%d\t%d\t%d\n",i+1, ti, tam, tex);
        wr = write(fd, buff2, MAX);
        if(wr < 0){
            printf("Error al escribir \n");
            break;
        }
    }

    close(fd);
    return 0;
}