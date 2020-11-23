## How C files are compiled, Makefiles, argc/argv, stdin/stdout/sderr, piping, file IO

## COMPILATION STEPS
1. Preprocessing: reads your sintax, ignores comments, etc
2. Compilation: converts your c code into assembly code (readable by human)
3. Assembly step: converts assembly code to machine instructions (not readable by human)
4. Linking step: gcc uses its built in linker to bring binaries for all external  
functions used (functions from <stdio.h>, "yourlibrary.h" etc.)  
add to our source code and creates the final executable  

## MAKEFILES
Are used to automate and make compilation of multiple files easy and efficient.  
Sintax such as ``gcc main.c foo.c bar.c ...`` allows for compilation of multiple files together into one executable.  

```
# makefile
all: main.c 
    gcc -o main main.c foo.c
```
```console
make # does all steps you specified with one command
```
<br>
A better makefile would be one that allows for separate compilation and assembly of files,  
and then finally link them all together for the final executable. This lets you to save on compilation time of unchanged files in large projects.

```bash
# example
gcc -c main.c               # -c tells gcc stop after the assembly step 
gcc -c foo.c                # and give you the object code (.o file)
gcc -c bar.c
gcc main.o foo.o bar.o      # this step links everything together
```
The makefile for this is included ./makedemo

## ARGC/ARGV
Arguments are used to give custom inputs to a program.  
The given arguments can be further parsed inside the program and  
used for various purposes like, name of a file to open, how many actions to do, etc.
```c
# test.exe arg1 arg2
int main(int argc, char**argv){
    for (int i = 0 ; i< ; i++)
        printf("%s, ",argv[i]);     # will print test.exe, arg1, arg2,
}
```
argc represents the number of arguments, where minimum is 1 (the name of the executable)  
argv is an array of strings, where each element is an argument passed to our program


## STIN/STDOUT/STERR
``scanf("%d", &testInteger);`` reads from stdin  
``printf("Hello World!\n");`` writes to stdout  
``fprintf(stderr,"");`` writes to stderr  
Normally both sderr and stdout are printed into the console, and sdin is read from console.  
Each of these streams can be redirected or piped.  
Stdout of a program can be redirected into a file.
Stdout of a program can be piped into another program's stdin.


## PIPING and REDIRECTING
```bash
# Pipes the given string to out program, redirects the program's stdout to out.txt.
echo Hello World! | myprogram.exe > out.txt
```
```bash
# Pipes the stdout ls into the stdi on our program, and then stdout of ours into out.txt  
ls -l | myprogram.exe > out.txt
```

## FILE IO
"High level libraries":  <stdio.h>, <stdlib.h>
```c
FILE* infile = fopen("file1.txt", "r");
FILE* infile2 = fopen("file2.txt", "w");

char buf[BUF_SIZE];
fread(buf, 1, sizeof(buf), infile);
fprintf(infile2, "%s\n", buf);
```
"Lowest level (syscalls)": <unistd.h>, <fcntl.h>
```c
int fd = open("file1.txt", O_RDONLY);       # file descriptor 
int fd2 = open("file1.txt", W_RDONLY);      # just a unique integer for each file
                                            # some common file descriptors:
                                            # 0: stdin, 1: stdout, 2: stderr
char buf[BUF_SIZE];
read(fd, buf, sizeof(buf));
write(fd2, buf, sizeof(buf));
```

Fread and fprintf are all built on top of syscalls and have built in optimisations.  
You might need to use syscalls if you need your own optimisations.  