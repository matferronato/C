#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//gcc -pthread -o term term.c



void* print(void *arg){
	int * index = (int *)arg;
	int i = *index;
	while(1){
	printf("eu sou o %d\n", i);
	}
}


int main() {
		int i;
		int nThreads = 10;
    pthread_t threads[nThreads];

    for(i = 0; i < nThreads; i++) {    
			pthread_create(&threads[i], NULL, print, &i );
    }

    for(i = 0; i < nThreads; i++) {
			pthread_join(threads[i], NULL);
    }
    return 0;
}


