#include <stdio.h>
#include <stdlib.h>

//stin, stdout, stderr

#define BUF_SIZE 128

int main(int argc, char** argv){
  if (argc < 2 ){
    fprintf(stderr, "needs at least one argument");
    exit(1);
  }

  FILE* infile = fopen(argv[1], "r");
  
  char buf[BUF_SIZE];
  buf[BUF_SIZE-1] = '\0';  
 
  while ( fread(buf, 1, sizeof(buf)-1, infile) !=0 ){
  	fprintf(stdout,"%s",buf);
	memset(buf, 0, BUF_SIZE);
  }

  return(0);
}

