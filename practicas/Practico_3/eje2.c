#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXP 1024

int main(int argc, char *argv[]) {

    int fd, n;
    char buff[MAXP];

    fd = open("data.txt", O_RDONLY);
    if (fd < 0) {
        printf("El archivo no pudo ser abierto \n");
    }
    while (n = read(fd, buff, MAXP)) {

        printf("%s", buff);

    }
    printf("\n");

    close(fd);

    return 0;
}
