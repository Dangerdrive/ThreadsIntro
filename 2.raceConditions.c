#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void *routine() {
    for (int i = 0; i < 100000; i++) {
        mails++;
}
}

int main() {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return 1;
    };
    /*
    Race conditions only occur after a certain number of iterations because
    in a lower number of iterations the thread finishes execution before the
    other thread is created
    */
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        return 2;
    };
        /*
    With a bigger number of iterations, the second thread starts and the first thread
    still running, causing it to read/increment/write at the same time.
    */
    if (pthread_join(t1, NULL) != 0) {
        return 3;
    };
    if (pthread_join(t2, NULL) != 0) {
        return 4;
    };
    printf("number of mails %d\n", mails);
}

//compile with -pthread
