## Lab asignment for week8

Your are to design a queue system for QelizXidmet - a not so successful competitor to AsanXidmet.
At QelizXidmet instead of making their customers' queuing experience as easy as possible they do the opposite.
You are to design a basic text based UI and the underlying queue system.

***1. The UI:***   
After every action the UI prints the current queue of the waiting persons.
The ui should be implemented inside a while loop that keeps looping and accepting user input until the program needs to finish.
The ui also lets the operator to type the key "q" which will end the program. 

***2. The Queue:***  
The program should start with a queue of 5 people already in it.
When a person is selected as the lucky customer they are moved to the end of the queue which means they will be served the last.
The ui will let the operators of the QelizXidmet queue to keep entering people's names and move them to the back of the queue just to be able to mess with them.

***3. Features:***  
The ui lets the operator enter any name and that person is chosen as a lucky customer.  
Every time a person is selected as the lucky customer they are moved to the back of the queue.  
The ui also lets the operator to type "admit" which admits the first person in the queue into QelizXidmet therefore removing that person from the queue.   
Before quitting the program, any dynamic memory needs to be freed with free() and any pointer used to point there set to NULL.  
<br>

Grading: 2/10 for a working ui, 2/10 for each of the 4 features.
<br>
```c
//Freeing dynamically allocated memory:
#include <stdlib.h>
int *ptr = (int*)malloc(sizeof(int));
free(ptr);
ptr = NULL; //ensures program consistently crashing if the code allows for illegal memory access
```

```c
//example of the state machine for the ui:
#include <stdio.h> 
#include <string.h>
#include <stdbool.h> 

char input[256];
bool quit = 0;
while(!quit)
{
  scanf( "%s" , input);
  if (strcmp(input,"quit") == 0)
  {
    quit = 1;
  }
  else if (strcmp(input,"admit") == 0)
  {
    //do something
  }
  //...
}

```


### Program example
```
queue: Turgut, Nazrin, Nigar, Kamran, Eljan
enter a comand:
```
user enters Nazrin
```
queue: Turgut, Nigar, Kamran, Eljan, Nazrin
enter a comand:
```
user enters Turgut
```
queue: Nigar, Kamran, Eljan, Nazrin, Turgut
enter a comand: 
```
user enters admit
```
Nigar was admitted
queue: Kamran, Eljan, Nazrin, Turgut
enter a comand: 
```