#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS     10

int fib[NUM_THREADS] = {0};

void PrintFibonacci(void *threadid) {

    int tid = (int) threadid;

    if (tid == 0) {
        fib[tid] = 0;
    } else if (tid == 1) {
        fib[tid] = 1;
    } else {
        fib[tid] = fib[tid - 1] + fib[tid - 2];
    }

    printf("El hilo %d calculo el valor %d de la serie: %d\n", tid, tid, fib[tid]);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    int t;
    int ret;

    for (t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintFibonacci, (void *) t);
        ret = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}

