#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

    int pidC, status;

    printf("PADRE de PID: %d \n", getpid());

    pidC = fork();

    if (pidC > 0) {
        wait(&status);
        if (WIFEXITED(status)) {
            printf("HIJO FINALIZADO correctamente con STATUS: %d \n", WEXITSTATUS(status));
        } else {
            printf("HIJO FINALIZADO erroneamente con STATUS: %d \n", WEXITSTATUS(status));
        }


    } else if (pidC == 0) {
        printf("HIJO de PID: %d \n", getpid());
        exit((getpid() % 2) + 100);
    }

    return 0;
}
