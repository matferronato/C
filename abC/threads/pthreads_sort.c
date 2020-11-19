#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//gcc -pthread -o term term.c


struct package{
	int *ptr;
	int size;
};

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void print(int *vet, int size){
	for(int i = 0; i < size; i ++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}




void swap(int *a, int *b)
{
   int t;
   t  = *b;
   *b = *a;
   *a = t;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	// Create temp arrays
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of L[]
	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	// Copy the remaining elements of R[]
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}


void unshuffle(void *arg){
	struct package *pkt =  (struct package*)arg;
	qsort(pkt->ptr, pkt->size, sizeof(int), cmpfunc);
}

void suffle(int *vet, int size){
	for(int i = 0; i < size; i++){
		vet[i] = rand() % size;
	}
}

int main() {

		int i, size = 2000, nThreads = 5;
		int vet[size];
		struct package pkts[nThreads];
		pthread_t threads[nThreads];
		srand(time(NULL));
		
		suffle(vet, size);

		
    for(i = 0; i < nThreads; i++) {
    	pkts[i].ptr = &vet[i*(size/nThreads)];
    	pkts[i].size = (size/nThreads);    
			pthread_create(&threads[i], NULL, unshuffle, &pkts[i]);
    }

    for(i = 0; i < nThreads; i++) {
			pthread_join(threads[i], NULL);
    }
		merge(vet, 0, ((size/2)-1)/2, (size/2)-1);
		merge(vet, (size/2), ((size/2)+(size-1))/2 , (size-1));		
		merge(vet, 0, (size-1)/2, size-1);		
		print(vet, size);    
    return 0;
}


