```c
// int * ptr = x; (x is value that's an address in ram);
// *x is the value somewhere else. x points to that somewhere else
// ram
// addr 0 : 41234234
// addr 1 : 5
// addr 2 : 16 
// addr 3 : 234234 
// int * ptr = 0;
// *ptr is 41234234
//
    // before the funct -> int *param = &a;
// funct (int *param){
//  param ++;   // youre ad addr 6 now
//  *param += 10;   // youre changing value of b. don't do this. mb it's segmentation fault if b is not at 6
//
//}

// int main(){
//    int a = 5;
//    int b = 6;
//    int arr[10];
//    funct(arr)
//
//
//  }
//
```