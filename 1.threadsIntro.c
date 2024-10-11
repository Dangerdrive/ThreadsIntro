#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine() {
    printf("start test from threads\n");
    sleep(3);
    printf("end test from threads\n");
}

int main() {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return 1;
    };
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        return 2;
    };
    if (pthread_join(t1, NULL) != 0) {
        return 3;
    };
    if (pthread_join(t2, NULL) != 0) {
        return 4;
    };
}

//compile with -pthread
