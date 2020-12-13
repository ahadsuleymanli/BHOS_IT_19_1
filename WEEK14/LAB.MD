# WEEK14 LAB
An exercise on iterating over and swapping linked lists.

Write a program that takes a series of inputs from the user in two phases.  
In the first phase the user enters numbers and each of them get added to a linked list.   
After a while the user enters, DONE and the program switches to the 2nd phase.  
At this phase the user enter a number and the program will swap node that has the number with its next node.    
Each number node can be swapped around only once.  
The program also prints the result after each swap.  
The program exits when the user types DONE again.  

## Pay attention to
Don't swap out values. Youre only allowed to swap the nodes themselves.  
You can store a boolean to keep track of its swapped status inside the node.    
Don't create new nodes after first stage is done.  
You can you <string.h> in this asignment.  

```
Enter numbers to add to your list:
5
99
15
15
1
2
5
5
DONE
Type two numbers to swap them around:
5
result: 99 5 15 15 1 2 5 5
99
No swap candidates found. Try again:
2
result:99 5 15 15 1 5 2 5
2
No swap candidates found. Try again:
DONE
```

```c
//append function for your ease of use
void append(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref;  /* used in step 5*/
   
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. This new node is going to be the last node, so make next  
          of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
   
    /* 6. Change the next of last node */
    last->next = new_node; 
    return;     
}
```