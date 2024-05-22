#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signalManager(int signal_num);

int main() {

    signal(SIGINT, &signalManager);
    signal(SIGTSTP, &signalManager);

    while (1) {
        sleep(5);
        printf("Esperando senial \n");

    }

    return 0;
}

void signalManager(int signum) {
    signal(signum, &signalManager);

    if (signum == SIGINT) {
        printf("Ctrl + C \n");
    } else if (signum == SIGTSTP) {
        exit(0);
    } else return;
}
