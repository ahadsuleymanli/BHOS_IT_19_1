# PROCESSES, CONTEXT, THREADS

## PThread library
We will be using the PThread library, it is for Linux.    
I recommend using linux for this because everything is included there. For windows you will have to do much more work and research.  

```c
#include <stdio.h>
#include <pthread.h>

void * hello(void *input) {
    printf("%s\n", (char *)input);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t tid;
    pthread_create(&tid, NULL, hello, "hello world");
    pthread_join(tid, NULL);
    return 0;
}
```

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct args {
    char* name;
    int age;
};

void *hello(void *input) {
    printf("name: %s\n", ((struct args*)input)->name);
    printf("age: %d\n", ((struct args*)input)->age);
}

int main() {
    struct args *Allen = (struct args *)malloc(sizeof(struct args));
    char allen[] = "Allen";
    Allen->name = allen;
    Allen->age = 20;

    pthread_t tid;
    pthread_create(&tid, NULL, hello, (void *)Allen);
    pthread_join(tid, NULL);
    return 0;
}
```

compile with:

```
gcc -o helloworld helloworld.c -lpthread
```

### Reading material
http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/9-PThread/Introduction.html   
Go through steps 1, ~~2,~~ 3. (Don't do step 2)
If you have linux try creating multiple threads and make them print stuff!  

