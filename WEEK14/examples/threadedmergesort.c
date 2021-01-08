#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100000
#define MAX_DEPTH 3

void fillArr(int from[], int to[], int num){
    for (int i = 0 ; i<num ; i++)
	to[i] = from[i];
}

void merge(int arr[], int l, int m, int r){
    int i=0, j=0, k=l;
    int n1 = m - l + 1;
    int n2 = r - m;

    int leftArr[n1];
    int rightArr[n2];

    // filing temp arrays:
    fillArr(arr+l, leftArr, n1);
    fillArr(arr+m+1, rightArr, n2);

    while(i<n1 && j<n2){
	if (leftArr[i] <= rightArr[j]){
	   arr[k] = leftArr[i];
	   i++;
	}
	else{
	   arr[k] = rightArr[j];
	   j++;
	}
	k++;
    }
    //copying leftoever elements from temp arrays
    while (i < n1){
	arr[k] = leftArr[i];
	i++;
	k++;
    }
    while(j < n2){
	arr[k] = rightArr[j];
	j++;
	k++;
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

struct Args{
    int* arr;
    int l;
    int r;
    int depth;
};

void* mergeSortRunner(void* args){
    struct Args argsL;
    struct Args argsR;
    pthread_t tidL;
    pthread_t tidR;

    int l = ((struct Args*)args)->l;
    int r = ((struct Args*)args)->r;
    int* arr = ((struct Args*)args)->arr;
    int m = l + (r-l)/2;
    int depth = ((struct Args*)args)->depth;

    argsL.arr = arr;
    argsL.l = l;
    argsL.r = m;
    argsL.depth = depth+1;
    argsR.arr = arr;
    argsR.l = m+1;
    argsR.r = r;
    argsR.depth = depth+1;

    if(l < r) {

        if (depth < MAX_DEPTH){
            pthread_create(&tidL, NULL, mergeSortRunner, &argsL);
            pthread_create(&tidR, NULL, mergeSortRunner, &argsR);

            pthread_join(tidL, NULL);
            pthread_join(tidR, NULL);
        }
        else{
            mergeSortRunner(&argsL);
            mergeSortRunner(&argsR);
        }

        merge(arr, l, m, r);
    }
}


int main(){
    int unsorted[SIZE];
    int arrSize = sizeof(unsorted)/sizeof(unsorted[0]);
    struct Args args;

    args.arr = unsorted;
    args.l = 0;
    args.r = arrSize-1;
    args.depth = 0;

    // printArray(unsorted, arrSize);
    mergeSortRunner(&args);
    // printf("sorted:\n");
    // printArray(unsorted, arrSize);
    return 0;
}
