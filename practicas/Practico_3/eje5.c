#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <linux/fs.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[]) {

    int st;
    struct stat buff;

    st = stat(argv[1], &buff);

    if (st != 0) {
        printf("Hubo un error al ejecutar stat \n");
        return st;
    }

    printf("Inodo: %d \n Nro Enlaces Fisicos: %d \n ID Usuario Propietario: %d \n ID Grupo Propietario: %d \n Size en bytes: %d \n Size del bloque para E/S: %d \n Nro Bloques Asignados: %d \n",
           buff.st_ino, buff.st_nlink, buff.st_uid, buff.st_gid, buff.st_size, buff.st_blksize, buff.st_blocks);

    printf("Hora de ultimo acceso: %s", ctime(&buff.st_atime));

    printf("Permisos: %#o \n", buff.st_mode & ~(S_IFMT));

    if (S_ISREG(buff.st_mode)) {
        printf("Tipo de archivo: Regular \n");
    }

    printf("Nro Mayor Dispositivo Fisico: %d \n Nro Menor Dispositivo Fisico: %d \n", major(buff.st_dev),
           minor(buff.st_dev));

    return 0;
}	
