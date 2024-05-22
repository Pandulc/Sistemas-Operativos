#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXP 1

int verifying();

int reading(int);

int main(int argc, char *argv[]) {

    int cnd;

    printf("Verificando...\n");

    do {
        cnd = verifying();
    } while (cnd != 0);

    return 0;

}

int verifying() {
    int op, ret;

    while ((op = open("data.txt", O_RDONLY)) == -1) {
    }

    ret = reading(op);

    close(op);

    return ret;
}

int reading(int op) {

    char buff[MAXP];

    read(op, buff, MAXP);

    if (buff[0] == '0') {
        exit(0);
    }

    return 1;
} 
