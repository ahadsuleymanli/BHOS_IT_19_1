#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 10240

char *handleGetline(char **str, int *n, FILE *stream, char *infileBuff){
    //read from stdin
    int linesRead = -1;
    do{
        linesRead = getline(str, n, stdin);
        if (linesRead<0)
            break;
    }while (linesRead<1 || *str[0]=='\n' );     // ignore empty newlines

    if (linesRead<0){                  
        fprintf(stderr, "Mismatch in input and output file line numbers.\n");
        fprintf(stderr, "Stdin: %s\n", *str);
        fprintf(stderr, "Expected: %s\n", infileBuff);
    }
    return *str;
}

int handleComparison(char *stdinBuff, char *infileBuff){
    int retval = strcmp (infileBuff, stdinBuff);
    if (retval != 0){
        fprintf(stderr, "Line missmatch:\n");
        fprintf(stderr, "Stdin: %s\n", stdinBuff);
        fprintf(stderr, "Expected: %s\n", infileBuff);
    }
    return retval;
}


int main(int argc, char** argv){
    char infileBuff[BUF_SIZE];
    char *stdinBuff = (char*)malloc(BUF_SIZE*sizeof(char));
    int stdinBuffSize = BUF_SIZE;
    FILE* infile;
    bool matches = true;

    if (argc < 2 ){
        fprintf(stderr, "you need to specifyt a filename.\n");
        exit(1);
    }

    infile = fopen(argv[1], "r");
    
    while(fgets(infileBuff, BUF_SIZE, infile) != NULL){
        if (infileBuff[0] == '\n')
            fgets(infileBuff, BUF_SIZE, infile) != NULL;

        if (handleGetline(&stdinBuff, &stdinBuffSize, 0, infileBuff) == NULL){
            matches = false;
            break;
        }
        if (stdinBuff[0] != '\0' && infileBuff[0] != '\0' && handleComparison(stdinBuff, infileBuff) != 0){
            matches = false;
            break;
        }
        stdinBuff[0] = '\0';
        infileBuff[0] = '\0';
    }

    fclose(infile);
    if (stdinBuff != NULL)
        free(stdinBuff);

    if (matches){
        printf("Passed.");
    }
    else{
        printf("Didn't pass.");
    }

}