#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXP 8

int main(int argc, char *argv[]) {

    int fd, wr, c, cond;
    char buff1[MAXP] = {'M', 'E', 'N', 'S', 'A', 'G', 'E', '1'};
    char buff2[MAXP] = {'M', 'E', 'N', 'S', 'A', 'G', 'E', '2'};


    do {
        fd = open("comunicador.txt", O_CREAT | O_WRONLY, 0644);

        if (fd < 0) {
            printf("Error al crear el archivo \n");
        }

        wr = write(fd, buff1, MAXP);
        close(fd);

        printf("Quiere cambiar el mensaje? \n 1- Si \n 0- No \n");
        scanf("%d", &c);

        if (c == 1) {
            fd = open("comunicador.txt", O_CREAT | O_WRONLY, 0644);
            wr = write(fd, buff2, MAXP);
            close(fd);
            if (wr < 0) {
                printf("No pude escribir el buff2 \n");
            }
        }
        printf("Realiza otra iteracion? \n 1- Si \n 0- No \n");
        scanf("%d", &cond);


    } while (cond != 0);

    return 0;
}
