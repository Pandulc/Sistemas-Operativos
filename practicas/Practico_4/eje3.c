#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void write0();

void write1();

int main(int argc, char *argv[]) {

    int op;
    int con = 1;


    while (con == 1) {
        printf("0- Salir \n1- Continuar\n");
        scanf("%d", &op);
        switch (op) {
            case 0:
                write0();
                break;
            case 1:
                write1();
                break;
            default:
                printf("Opcion no valida \n");
                break;
        }
        printf("Desea hacer otra prueba? \n 1- Si \n 0- No \n");
        scanf("%d", &con);
        remove("data.txt");
    }
    return 0;
}

void write0() {
    int fd, wr;
    char buff[1] = {'0'};
    fd = open("data.txt", O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        printf("No pude abrir el archivo \n");
    }

    wr = write(fd, buff, 1);

    if (wr < 0) {
        printf("Error al escribir \n");
    }

    close(fd);
}

void write1() {
    int fd, wr;
    char buff[1] = {'1'};
    fd = open("data.txt", O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        printf("No pude abrir el archivo \n");
    }

    wr = write(fd, buff, 1);

    if (wr < 0) {
        printf("Error al escribir \n");
    }

    close(fd);
}
