#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    printf("Verificando...\n");

    while (open("data.txt", O_RDONLY) == -1) {
    }

    return 0;
}
