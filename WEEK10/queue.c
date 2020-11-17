#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
 int data;
 char name[256];
 struct Node * next;
};



void addToTail(struct Node** tail, int data, char *name){ 
  (*tail) -> next = (struct Node*) malloc(sizeof(struct Node));
  (*tail) -> next -> data = data;
  strcpy((*tail)->next->name, name);
  (*tail) -> next -> next = NULL;

  (*tail) = (*tail) -> next;
}

struct Node* popTail(struct Node** head, struct Node** tail){ 
  struct Node *iter = *head;
  struct Node *lastNode;
  if (iter == NULL)
    return NULL;
  else if (iter->next == NULL){
    (*head) = NULL;
    (*tail) = NULL;
    return iter;
  }
  while(iter != NULL && iter->next != NULL && iter->next->next != NULL)	// finding one before last
    iter = iter->next;

  lastNode = iter->next;
  iter -> next = NULL;
  (*tail) = iter;
  return lastNode;


}

void addToHead(struct Node** head, int data, char *name){
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode -> data = data;
  strcpy(newNode->name, name);
  newNode -> next = (*head);
  *head = newNode;
}

struct Node* getTail(struct Node* iter){
  while(iter != NULL && iter->next != NULL)
    iter = iter->next;
  return iter;
}


struct Node* popFromHead(struct Node** head)
{
  struct Node *nodePtr;
  if ((*head) == NULL)
    return NULL;
  else if ((*head)->next == NULL)
  {
    nodePtr = *head;
    (*head) = NULL;
    return nodePtr;
  }
  nodePtr = *head;
  (*head) = (*head)->next;
  return nodePtr;
}


void printList(struct Node* iter){
  while( iter != NULL){
    printf("%d, ",iter->data);
    iter = iter->next;
  }
  printf("\n");
}


int main()
{
  struct Node *head = (struct Node*) malloc(sizeof(struct Node));
  struct Node *tail = head;
  struct Node *tempPtr;
  head -> data = 0;
  
  addToTail(&tail, 1, "");

  addToTail(&tail, 2, "");
 
  addToTail(&tail, 3, "");

  addToHead(&head, 99, "");

  addToHead(&head, 98, "");
  addToHead(&head, 97, "");

  printList(head);

  tempPtr = popTail(&head, &tail);
  printf("popped: %d\n",tempPtr->data);

  free(tempPtr);  
  tempPtr = NULL;
 
  tempPtr = popTail(&head, &tail);
  printf("popped: %d\n",tempPtr->data);
 
  free(tempPtr);
  tempPtr = NULL;
 
  printList(head);


  tempPtr = popFromHead(&head);
  printList(head);
}
