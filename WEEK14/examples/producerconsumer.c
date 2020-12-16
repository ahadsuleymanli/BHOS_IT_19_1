#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 4

int buffer[BUF_SIZE];
sem_t full;
sem_t empty; 
int i_producer;
int i_consumer;

bool exitThreads;

pthread_mutex_t cons_mutex;

void* producer(void* args){
    int item;
    char inputTemp[256]; 
    while(!exitThreads){
        scanf("%s",inputTemp);
        if ( strcmp(inputTemp, "quit")==0 ){
            exitThreads = true;
            sem_post(&full);
            sem_post(&full);
            break;
        }else{
            item = atoi(inputTemp);
        }

        sem_wait(&empty);   // sleep if can't decrement, otherwise decrement to minimum of 0

        buffer[i_producer] = item;

        i_producer = (i_producer + 1) % BUF_SIZE;

        sem_post(&full);
    }
    printf("producer finished.\n");
}

void* consumer(void* args){

    while(!exitThreads){
        sem_wait(&full);
        if (exitThreads){
            break;
        }
        sleep(1);

        pthread_mutex_lock(&cons_mutex);

        printf("%s: consumed %d\n", (char*)args, buffer[i_consumer]);
        i_consumer = (i_consumer + 1) % BUF_SIZE;

        pthread_mutex_unlock(&cons_mutex);

        sem_post(&empty);
    }
    printf("%s finished.\n", (char*)args);

}

int main(){
    pthread_t pid_prod, pid_cons, pid_cons2;

    i_producer = 0;
    i_consumer = 0;
    char cons_name1[] = "cons1";
    char cons_name2[] = "cons2";
    exitThreads = false;

    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUF_SIZE);


    pthread_create(&pid_prod, NULL, producer, NULL);
    pthread_create(&pid_cons, NULL, consumer, cons_name1);
    pthread_create(&pid_cons2, NULL, consumer, cons_name2);


    pthread_join(pid_prod, NULL);
    pthread_join(pid_cons, NULL);
    pthread_join(pid_cons2, NULL);


    return 0;
}