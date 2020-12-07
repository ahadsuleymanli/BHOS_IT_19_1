## SORTING, DIVIDE-AND-CONQUER SORTING ALGORITHMS (MERGE SORT), TREE SORT


#### Bubble sort example:

```c
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
```

#### [Merge sort example](../mergesort.c) 

#### [Tree sort example](../treesort.c)


### Videos demonstrated:
https://www.youtube.com/watch?v=XaqR3G_NVoo