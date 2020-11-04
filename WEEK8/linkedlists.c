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
 (*tail) = (*tail) -> next;
 (*tail) -> data = data;
 strcpy((*tail)->name, name);
 (*tail) -> next = NULL;
}

void printList(struct Node* iter){
 while( iter != NULL){
	printf("%d-%s, ",iter->data,iter->name);
	iter = iter->next;
 }
 printf("\n");


}

int main(){
 struct Node *head = (struct Node*) malloc(sizeof(struct Node));
 head -> data = 0;

 struct Node *tail = head;
 
 addToTail(&tail, 1, "name1");
 
 

 addToTail(&tail, 2, "name2");

 addToTail(&tail, 3, "name3");

 printList(head);

 //deleting node 2
 

 struct Node *nodePtr = head->next;
 
 // saving reference to the node we will delete 
 struct Node *tempNode = head->next->next;
 

 nodePtr -> next = nodePtr -> next -> next;
 printf("deleted node:%d-%s\n",tempNode->data,tempNode->name);
 free(tempNode);
 tempNode = NULL;

 printf("deleted node:%d-%s\n",tempNode->data,tempNode->name);
 printList(head);


 return 0;
}

