#include <stdio.h>
#include <stdlib.h>
#include "bin_max_sum.h"

struct Node* newNode(int value) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL; 
    return (node); 
}

int addNodes(struct Node* iter)
{
  if (iter == NULL)
    return 0;
  return iter->value + addNodes(iter->left) + addNodes(iter->right);
}

int getMaxPath(struct Node* iter)
{
  if (iter == NULL)
    return 0;
  int left = getMaxPath(iter->left);
  int right = getMaxPath(iter->right);
  if (left >= right)
    return iter->value + left;
  else
    return  iter->value + right;
}

