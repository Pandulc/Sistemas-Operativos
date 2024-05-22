#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signalManager(int signal_num);

void signalManagerC(int signal_num);

int pid, pidC, pidP;

int main() {

    int status;

    printf("PADRE de PID: %d \n", getpid());
    pidP = getpid();
    pid = fork();

    if (pid > 0) {
        signal(SIGINT, &signalManager);
        signal(SIGTSTP, &signalManager);
        pidC = pid;

        wait(&status);
    } else if (pid == 0) {
        signal(SIGINT, &signalManagerC);
        signal(SIGTSTP, &signalManagerC);

        while (1) {
            sleep(5);
        }

    }

    return 0;
}

void signalManager(int signum) {
    int ret;
    printf("PID: %d, numero senial: %d \n", pid, signum);
    signal(signum, &signalManager);

    if (pidC == pid) {
        ret = kill(pidC, signum);

        printf("retorno: %d \n", ret);
        fflush(stdout);
    }

}

void signalManagerC(int signum) {
    signal(signum, &signalManagerC);

    if (signum == SIGINT) {
        printf("Hijo dice: Ctrl + C \n");
        fflush(stdout);
    } else if (signum == SIGTSTP) {
        kill(getppid(), 9);
        exit(0);
    } else return;
}
