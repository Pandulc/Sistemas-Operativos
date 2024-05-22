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

int main(int argc, char *argv[]) {

    int rd, wr, pidC1, pidC2;
    char buff2[MAXP];
    int pd[2];

    pipe(pd);

    pidC1 = fork();

    if (pidC1 != 0) {
        int status;
        if (pidC1 < 0) {
            printf("Error en el fork \n");
            return 1;
        }

        pidC2 = fork();
        if (pidC2 > 0) {
            wait(&status);
            if (WIFEXITED(status)) {
                printf("El segundo hijo termino correctamente \n");
            } else {
                printf("El segundo hijo termino erroneamente \n");
            }
        } else {

            rd = read(pd[0], buff2, MAXP);

            if (rd < 0) {
                printf("No pude leer \n");
                return 1;
            }
            printf("La fecha es: %s", buff2);
        }
    } else {
        time_t time1 = time(NULL);
        char buff1[MAXP];

        //Otra forma fachera de guardar todo
        /*struct tm *time_st;
        time_st = localtime(&time);
        sprintf(buff1, "%d : %d : %d", time_st->tm_hour, time_st->tm_min, time_st->tm_sec);*/

        sprintf(buff1, "%s", ctime(&time1));

        wr = write(pd[1], buff1, MAXP);
        if (wr < 0) {
            printf("No pude escribir \n");
            return 1;
        }
    }

    return 0;
}

