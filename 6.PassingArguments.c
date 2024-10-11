#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};



void *get_prime(void *arg) {
	//sleep(1);
	int index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int main() {

	int thread_count = 10;
    pthread_t tt[thread_count];
    for (int i = 0; i < thread_count; i++) {
		int *a = malloc(sizeof(int));
		*a = i;
        if (pthread_create(&tt[i], NULL, &get_prime, a) != 0) {
        perror("failed to create thread\n");
    }
    //printf("Thread %d started\n", i);


    }
    for (int i = 0; i < thread_count; i++) {
        if (pthread_join(tt[i], NULL) != 0) {
            perror("failed to join thread\n");
    }
    //printf("Thread %d ended\n", i);
    }

}
