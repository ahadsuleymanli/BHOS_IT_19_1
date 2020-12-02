#include <stdio.h>
#include <stdlib.h>


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


void mergeSort(int arr[], int l, int r){
    if (l < r){
	int m = l + (r-l)/2;

	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	
	merge(arr, l, m, r);
//	printArray(arr+l, r);
    }
}





int main(){
    int unsorted[] = {1,5,2,3,4,9,11,0,-5};
    int arrSize = sizeof(unsorted)/sizeof(unsorted[0]);

    printArray(unsorted, arrSize);
    mergeSort(unsorted, 0, arrSize-1);
    printf("sorted:\n");
    printArray(unsorted, arrSize);
    return 0;
}
