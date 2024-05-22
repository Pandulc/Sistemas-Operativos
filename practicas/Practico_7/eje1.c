#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedList.h"

#define MAX_LENGHT 100
#define MAX_TIME_CLK 150

int particionadoEstatico(int, char **);

int particionadoDinamico(int, char **);

int main(int argc, char *argv[]) {
    int code;
    if (*argv[1] == '0') {
        code = particionadoEstatico(argc, argv);
    } else if (*argv[1] == '1') {
        code = particionadoDinamico(argc, argv);
    }

    return code;
}

int particionadoEstatico(int argv, char *argc[]) {
    FILE *fd;
    struct hole holes[6];
    char *token;
    char str[MAX_LENGHT];
    int size, pid, ti, tam, tex;
    int i = 0;
    int errors = 0;
    int memused = 0;
    float fragint = 0;
    float fragext = 0;
    float promfragint, promfragext;

    if (*argc[2] == '0') {
        struct hole h1 = {8, 0};
        holes[0] = h1;
        struct hole h2 = {8, 0};
        holes[1] = h2;
        struct hole h3 = {8, 0};
        holes[2] = h3;
        struct hole h4 = {8, 0};
        holes[3] = h4;
        struct hole h5 = {8, 0};
        holes[4] = h5;
        //Representacion del SO
        struct hole h6 = {8, 1};
        holes[5] = h6;
    } else {
        struct hole h1 = {4, 0};
        holes[0] = h1;
        struct hole h2 = {4, 0};
        holes[1] = h2;
        struct hole h3 = {8, 0};
        holes[2] = h3;
        struct hole h4 = {8, 0};
        holes[3] = h4;
        struct hole h5 = {16, 0};
        holes[4] = h5;
        struct hole h6 = {16, 0};
        holes[5] = h6;
    }

    fd = fopen("input.txt", "r");
    if (fd == NULL) {
        printf("Error al abrir el archivo \n");
    }
    fscanf(fd, "%d", &size);
    struct process processes[size];

    while (fscanf(fd, "%d\t%d\t%d\t%d", &pid, &ti, &tam, &tex) != EOF) {
        struct process process;
        process.pid = pid;
        process.timea = ti;
        process.sizep = tam;
        process.timeex = tex;
        processes[i] = process;
        i++;
    }

    //Reseteo el i para usarlo como clk
    i = 0;
    while (i < MAX_TIME_CLK) {
        for (int j = 0; j < size; ++j) {
            //Si el clk es igual al tiempo de arribo del proceso j
            if (i == processes[j].timea) {
                int flag = 0;
                for (int k = 0; k < 5; ++k) {
                    //Si el proceso cabe en la particion y la particion no esta usada
                    if (processes[j].sizep <= holes[k].size && holes[k].full == 0) {
                        holes[k].full = 1;
                        holes[k].p = processes[j];
                        memused += processes[j].sizep;
                        fragint += (float) (holes[k].size - processes[j].sizep);
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    errors++;
                }
            }
            if (i == processes[j].timeex) {
                for (int k = 0; k < 5; ++k) {
                    if (holes[k].p.pid == processes[j].pid) {
                        holes[k].full = 0;
                    }
                }
            }
        }
        i++;
    }
    promfragint = fragint / size;
    promfragext = fragext / size;

    printf("\n Fragmentacion interna promedio: %f \n Fragmentacion externa promedio: %f \n Fallos de asignacion: %d \n Uso de memoria: %d\n",
           promfragint, promfragext, errors, memused);

    return 0;
}

int particionadoDinamico(int argv, char *argc[]) {
    FILE *fd;
    hnodo head = {56, 0};
    hpuntero holes = &head;
    char str[MAX_LENGHT];
    int size, pid, ti, tam, tex;
    int i = 0;
    int errors = 0;
    int memused = 0;
    float fragint = 0;
    float fragext = 0;
    float promfragint, promfragext;

    fd = fopen("input.txt", "r");
    if (fd == NULL) {
        printf("Error al abrir el archivo \n");
    }
    fscanf(fd, "%d", &size);
    struct process processes[size];

    while (fscanf(fd, "%d\t%d\t%d\t%d", &pid, &ti, &tam, &tex) != EOF) {
        struct process process;
        process.pid = pid;
        process.timea = ti;
        process.sizep = tam;
        process.timeex = tex;
        processes[i] = process;
        i++;
    }

    i = 0;

    while (i <= MAX_TIME_CLK) {
        for (int j = 0; j < size; ++j) {
            if (i == processes[j].timea) {
                errors += insertarEnLista(&holes, processes[j]);
            }
            if (i == processes[j].timeex){
                borrarProceso(&holes, processes[j]);
            }
        }
        i++;
    }

    return 0;
}


