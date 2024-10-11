#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine() {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
}
}

int main() {
    int i;
    pthread_t tt[4];
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 4; i++) {
        if (pthread_create(&tt[i], NULL, &routine, NULL) != 0) {
        return 1;
    }
    printf("Thread %d started\n", i);
    // if (pthread_join(tt[i], NULL) != 0) { //incorrect way: this way each thread begins and ends in each iteration, so they do not occur in parallel
    //     return 2;
    // }
    // printf("Thread %d ended\n", i);

    }
    //correct way, with another for loop
    for (i = 0; i < 4; i++) {
        if (pthread_join(tt[i], NULL) != 0) {
        return 2;
    }
    printf("Thread %d ended\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("number of mails %d\n", mails);
}
