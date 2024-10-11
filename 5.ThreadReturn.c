#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>


void *roll_dice() {
	int value = (rand() % 6)+ 1;
	int *result = malloc(sizeof(int));
	*result = value;
	printf("%d\n", value);
	return (void*) result;
}

int main() {
	int* result;
	srand(time(NULL));
	pthread_t thread, thread2;
	if (pthread_create(&thread, NULL, &roll_dice, NULL) != 0) {
		return 1;
	}

	if (pthread_create(&thread2, NULL, &roll_dice, NULL) != 0) {
		return 1;
	}


	if (pthread_join(thread, (void **) &result)!=0){
		return 2;
	}
	//result value is modified by join function
	printf("Result1: %d\n", *result);
	if (pthread_join(thread2, (void **) &result)!=0){
		return 2;
	}
	printf("Result2: %d\n", *result);
	//so the correct way it would be setting a different *result variable for each thread, otherwise we could not garantee the result would be printed correctly
	printf("Result: %d\n", *result);
	free(result);
}
