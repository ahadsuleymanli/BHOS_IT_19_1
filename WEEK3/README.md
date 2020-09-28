## Arrays and Pointers continued, 3D arrays (matrices) 
***Since this week's classes are not being held you will need to do a series of readings and asignemnts.***  
The reading are from the "The C Programming Language" by Brian Kernighan and Dennis Ritchie.  
This week you will learn pointer asignment, pointer dereferencing, working with character arays, iterating over 1D and 2D arrays.  
There are two asignments this week and they are due next tuesday before class.
<br>


### Readings and asignments for Tuesday 29th:
5.1 Pointers and Addresses  
```c
int *intPtr;    // declaration, points somewhere random
                // intPtr is how you access the address
                // *intPtr is how you access the value at the address
                // but since the pointer is not initialized
                // all operations on *intPtr are undefined and should not be done!
int x = 5;
intPtr = &x;    // now our pointer points to x's address
*intPtr = 10;   // we can "dereference" the pointer  
                // do whatever we want with the variable at the address
                // when using *intPtr, the "*" operation is called dereferencing operator
int y;
intPtr = &y;    // we can freely change where our pointer points to 
```
5.2 Pointers and Function Arguments  
5.3 Pointers and Arrays 

```c
// iterating over all elements of a 2D array
int arr2D[][2] = {{1,2},{3,4},{5,6}};
for (int i = 0 ; i<sizeof(arr2D)/sizeof(arr2D[0]) ; i++){
    for (int j = 0 ; j<sizeof(arr2D[0])/sizeof(int) ; j++)
        printf("%d ",arr2D[i][j]);
    printf("\n");
}
```
[Assignment1](ASSIGNMENT1.md)

<br>

### Readings and asignments for Wednesday 30th:
5.5 Character Pointers And Functions  
```c
char charArray[] = "foo";   // allocates an array of length 4: ['f','o','o','\n']
                            // charArray points to the first element

char *stringPtr = "bar";    // allocates a constant array of length 4: ['b','a','r','\n'], lvalue operations are undefined
                            // stringPtr points to the first element

*charArray = 'x';           // same as charArray[0] = 'x';
*charArray+1 = 'y';         // you can't do the same with stringPtr
*charArray+2 = 'z';         
                            // however you can point to an actual array with the pointer:
stringPtr = charArray;      // this does the same thing as the following line:
stringPtr = &(charArray[0]);// points to the address of the first element
```
5.7 Multi-dimensional Arrays  
5.8 Initialization of Pointer Arrays  
5.9 Pointers vs Multi-dimensional Arrays  

[Assignment2](ASSIGNMENT2.md)  
