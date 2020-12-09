#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>


#define NUM_STEPS 100

pthread_mutex_t lock;

void* worker(void *input){
    sleep(2);

    pthread_mutex_lock(&lock);
    // critical section start

    *(int*)input = *(int*)input + 1;

    // critical section end
    pthread_mutex_unlock(&lock); 
}

int main(){
    pthread_t tidList[NUM_STEPS];
    int num = 0;

    for (int i = 0 ; i<NUM_STEPS ; i++){
        pthread_create(tidList+i, NULL, worker, &num);
    }

    for (int i = 0 ; i<NUM_STEPS ; i++){
        pthread_join(tidList[i], NULL);
    }

    printf("result %d\n", num);
    return 0;
}

