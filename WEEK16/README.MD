# Final exam prep

## Linked List delete question

```c
#include <stdio.h>
#include <stdlib.h>

/*
Question asks to write a function Node *deleteRange(Node *head, int low, int high); 
    that takes a linked list's head reference and deletes all nodes having low <= node.num <= high
    investigate the provided double pointer implementation. Figure out a single pointer implementation.
*/

typedef struct node
{
    int num;
    struct node *next;
} Node;

// double pointer implementation
Node *deleteRange(Node **head, int low, int high)
{
    // understand why this step is done
    while (head != NULL && (*head)->num >= low && (*head)->num <= high)
    {
        Node *temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
    if (head != NULL)
    {
        Node *current = (*head)->next;
        Node *previous = (*head);
        while (current != NULL)
        {
            if (current->num >= low && current->num <= high)
            {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
            else{
                previous = previous->next;
                current = current->next;
            }
        }
    }
    // modify the function to only use single pointer to head, 
    // and use this return head feature to reproduce the same result with the double pointer implementation 
    return *head;
}

void append(Node* iter, int num){
    while(iter->next!=NULL){
        iter = iter->next;
    }
    iter->next = (Node*) malloc(sizeof(Node));
    iter->next->num = num;
    iter->next->next = NULL;
}
void printLL(Node* iter){
    while(iter!=NULL){
        printf("%d, ",iter->num);
        iter = iter->next;
    }
    printf("\n");
}
int main(){
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    head->num = 1;
    append(head, 5);
    append(head, 11);
    append(head, 19);
    append(head, 4);
    append(head, 7);
    append(head, 2);

    printLL(head);

    deleteRange(&head, 1,11);

    printLL(head);

    return 0;
}
```