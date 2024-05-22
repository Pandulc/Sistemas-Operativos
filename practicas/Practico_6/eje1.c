#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAXP 5

sem_t mutex;
sem_t empty;
sem_t full;
int buffer[MAXP] = {0};

void down(sem_t *);

void up(sem_t *);

_Noreturn void *producer();

_Noreturn void *consumer();

void insert_item(int);

int remove_item();

int main(int argc, char *argv[]) {
    pthread_t producer_t, consumer_t;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, MAXP);
    sem_init(&full, 0, 0);

    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    sleep(100);

    sem_close(&mutex);
    sem_close(&empty);
    sem_close(&full);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

void *producer() {
    while (1) {
        sleep(2);
        down(&empty);
        down(&mutex);
        srand(time(NULL));
        insert_item(rand() % 100 + 1);
        up(&mutex);
        up(&full);
    }
}

void *consumer() {
    int item;
    sleep(10);
    while (1) {
        sleep(1);
        down(&full);
        down(&mutex);
        item = remove_item();
        up(&mutex);
        up(&empty);
    }
}

void down(sem_t *sem) {
    sem_wait(sem);
}

void up(sem_t *sem) {
    sem_post(sem);
}

void insert_item(int item) {
    for (int i = 0; i < MAXP; ++i) {
        if (buffer[i] == 0) {
            buffer[i] = item;
            printf("Producer: Inserte un elemento\n");
            break;
        }
        else if(i == MAXP - 1){
            printf("Se lleno el buffer \n");
            fflush(stdout);
            sleep(3);
        }
    }
}

int remove_item() {
    int item;
    for (int i = MAXP - 1; i >= 0; --i) {
        if (buffer[i] != 0) {
            item = buffer[i];
            buffer[i] = 0;
            printf("Consumer: Consumi un elemento\n");
            break;
        }
        else if (i == 0){
            printf("Se vacio el buffer \n");
            sleep(3);
        }
    }
    return item;
}
