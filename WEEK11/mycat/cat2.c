#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUF_SIZE 64

int main(int argc, char**argv){
  if(argc != 2)
    return(1);

  int fd = open(argv[1], O_RDONLY); // open uses a syscall direcly.
				    // 0 for stdin, 1 for stdout, 2 for stderr
  char buf[BUF_SIZE];
  while( read(fd, buf, sizeof(buf)) > 0 ){
    write(1, buf, sizeof(buf));
    write(2, "write action", 12);
    memset(buf, 0, sizeof(buf));
  }

  close(fd);
  return 0;
}
