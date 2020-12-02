#include <stdio.h>
#include <stdlib.h>
#include "bin_max_sum.h"

// treesort has time complexity of nlog(n)
//
// arr[16]
//
// tree:
// 1
// 2
// 3
// 4
// 16*4


void insert(struct Node* iter, int num, int *count){
  (*count) ++;
  if (iter==NULL)
    iter = newNode(num);
  else if (num <= iter->value){
    if (iter->left == NULL){
	iter->left = newNode(num);
	return;
    }
    insert(iter->left, num, count);
  }
  else{
    if (iter->right == NULL){
	iter->right = newNode(num);
	return;
    }
    insert(iter->right, num, count);

  }
}


void inorder(struct Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d \n", root->value); 
        inorder(root->right); 
    } 
}


int main(){
  
    int intList[] = {99, 1,2, 33,32,31,30,3,4,5,6, 12,13,14,15,16};
    //int intList[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    int numOperations = 0;
    
    struct Node* head;
    head = newNode(intList[0]);
    
    for (int i = 1 ; i<sizeof(intList)/sizeof(int) ; i++){
	insert(head, intList[i], &numOperations);

    }

    printf("num elements%d\n", sizeof(intList)/sizeof(int));

    inorder(head);
    
    printf("num of operations: %d", numOperations);

}
