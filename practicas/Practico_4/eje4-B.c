#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXP 100
#define MAXR 8

int main(int argc, char *argv[]) {

    int fd, rd, wr;
    int i = 0;
    char buff1[MAXP];
    char buff2[MAXP];

    while (1) {
        if (i % 2 == 0) {
            fd = open("comunicador.txt", O_RDONLY);
            if (fd < 0) {
                printf("No pude abrir el archivo \n");
            }
            rd = read(fd, buff1, MAXP);
            close(fd);
        }
        if (i % 2 == 1) {
            fd = open("comunicador.txt", O_RDONLY);
            if (fd < 0) {
                printf("No pude abrir el archivo \n");
            }
            rd = read(fd, buff2, MAXP);
            close(fd);
        }
        if (i != 0) {
            for (int j = 0; j < rd; j++) {
                if (buff1[j] != buff2[j]) {
                    char buffR[MAXR] = {'C', 'A', 'M', 'B', 'I', 'O', '!', '!'};
                    fd = open("comunicador.txt", O_WRONLY);
                    wr = write(fd, buffR, MAXR);
                    if(wr < 0){
                        printf("No pude escribir \n");
                    }
                    close(fd);
                    exit(0);
                }
            }
        }
        i++;
    }

    return 0;
}
