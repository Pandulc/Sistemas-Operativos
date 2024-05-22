#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

int fib[NUM_THREADS] = {0};
int ctrl = 0;

void *PrintFibonacci(void *threadid) {

    int tid = (int) threadid;

    while (tid != ctrl) {

    }

    if (tid == 0) {
        fib[tid] = 0;
    } else if (tid == 1) {
        fib[tid] = 1;
    } else {
        fib[tid] = fib[tid - 1] + fib[tid - 2];
    }

    printf("El hilo %d calculo el valor %d de la serie: %d\n", tid, tid, fib[tid]);

    ctrl++;
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    int t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, PrintFibonacci, (void *) t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}

