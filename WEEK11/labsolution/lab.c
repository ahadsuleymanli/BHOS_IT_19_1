/**
 * fgets is a function that returns a line from a document
 * char* fgets (char* str, int num, FILE* stream ); 
 * http://www.cplusplus.com/reference/cstdio/fgets/
 * 
 * implement a similar function
 * bool readLine(char* buf, int num, FILE* stream);
 * thar writes a line into buf, and returns true if a line could be read or whole buffer got filled.
 * return false if no character is read
 * http://www.cplusplus.com/reference/cstdio/fread/
 * */

#include <stdio.h>
#include <stdlib.h>
#include "bin_max_sum.h"

#define BUF_SIZE 512

char* readLine(char* buf, int num, FILE* stream){
    for (size_t i = 0; i < num-1; i++){
        if (fread(buf+i, 1, 1, stream) == 0){
            if (i==0){
                buf[i] = '\0';
                return NULL;
            }else{
                buf[i] = '\0';
                break;
            }
        }
        if ( buf[i] == '\n' ){
            buf[i] = '\0';
            break;
        }
        // else: keep reading
    }
    buf[num-1] = '\0';
    return buf;
}

struct Node* levelOrderInsert(int *numStack, int SIZE, int index){
    struct Node* tmp = NULL;
    if(index < SIZE){
        tmp = newNode(numStack[index]);
        tmp->value = numStack[index];
        tmp->left = levelOrderInsert(numStack, SIZE, 2*index + 1);
        tmp->right = levelOrderInsert(numStack, SIZE, 2*index + 2);
    }
    return tmp;
}

int main(int argc, char** argv){
    if (argc < 2 ){
        fprintf(stderr, "needs at least one argument");
        exit(1);
    }

    FILE* infile = fopen(argv[1], "r");
    if ( infile==NULL ){
        fprintf(stderr, "can't open the file");
        exit(2);
    }
    char buf[BUF_SIZE];

    int numStack[256];
    int numStackTop = -1;
    struct Node* head = NULL;

    for ( ; readLine(buf, BUF_SIZE, infile) != NULL;  ){
        // assuming single digits
        for (int i = 0; buf[i] != '\0' ; i++){
            if (buf[i] >= 48 && buf[i] <= 57){
                int temp = (int)(buf[i]-48);
                numStack [++numStackTop] = temp;
            }
        }
    }
    head = levelOrderInsert(numStack, numStackTop+1, 0);
    
    printf("max path sum of the tree is %d\n", getMaxPath(head));
    
    return 0;
}