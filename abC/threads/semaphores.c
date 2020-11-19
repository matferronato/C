#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

//gcc -pthread -o term term.c

sem_t thisSemaphore;
//pthread_mutex_t mutex;

void* print(void *arg){
	int * index = (int *)arg;
	
	while(1){
		printf("%d waiting \n", *index);
		sem_wait(&thisSemaphore);
		printf("i'm %d and i own critical section \n", *index);
		sem_post(&thisSemaphore);
	}
}


int main() {
		int i;
		int pckt[] = {1,2};
		int nThreads = 2;
		sem_init (&thisSemaphore , 0, 1);
    pthread_t threads[nThreads];

    for(i = 0; i < nThreads; i++) {    
			pthread_create(&threads[i], NULL, print, &pckt[i] );
    }

    for(i = 0; i < nThreads; i++) {
			pthread_join(threads[i], NULL);
    }
    return 0;
}


