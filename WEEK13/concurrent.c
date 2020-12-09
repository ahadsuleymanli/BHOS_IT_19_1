#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

struct Args{
    int num;
    bool ready; 
};

void* worker(void *input){
    struct Args* argsPtr = (struct Args*)input;

    argsPtr->ready = false;
    sleep(5);
    printf("processing for %d is complete.\n", argsPtr->num);
    argsPtr->ready = true;
}

int main(){
    struct Args args;
    pthread_t tid;

    args.ready = true;

    while(1){
        printf("enter a number: ");
        int temp;
        scanf("%d", &temp);
        if (args.ready){
            args.num = temp;
            printf("your request is taken\n");
            pthread_create(&tid, NULL, worker, &args);
        }
        printf("busy! try later!\n");
    }
    return 0;
}

