#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define MAXP 10

int main(int argc, char *argv[]) {

    int fd, fd2, rd, wr;
    char buff[MAXP];

    fd = open(argv[1], O_RDONLY);
    fd2 = open(strcat(argv[1], ".bak"), O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        printf("No se pudo abrir el archivo .txt \n");
    }

    if (fd2 < 0) {
        printf("No se puedo crear el archivo .bak \n");
    }

    while (rd = read(fd, buff, MAXP)) {

        wr = write(fd2, buff, rd);

        if (wr < 0) {
            printf("No se pudo escribir en el archivo \n");
            break;
        }
    }

    close(fd);
    close(fd2);
    return 0;
}
