# WEEK 11 LAB ASIGNMENT ON FILE IO AND STRING PARSING
## PART1
``fgets`` is a function that returns a line from a document  
``char* fgets (char* str, int num, FILE* stream );``  
http://www.cplusplus.com/reference/cstdio/fgets/  
implement a similar function  
``bool readLine(char* buf, int num, FILE* stream);``  
thar writes a line into buf, and returns true if a line could be read or whole buffer got filled.  
return false if no character is read.  
You should use ``fread`` to implement your function.  
http://www.cplusplus.com/reference/cstdio/fread/  
<br>
deadline due end of class.

```bash
# inflie
                 5
        2               29
    11     23       23      0
5     16  0   15  31   0   0   0
```
```bash
# outfile
another line:                  5
another line:         2               29
another line:     11     23       23      0
another line: 5     16  0   15  31   0   0   0

```
## PART2
Since all leaf nodes will exist in this binary tree, ie. it is a ***perfect tree***,  
it is relatively easy to parse it and build a tree data structure out of it. 
Build a binary tree from an input file and find the largest sum on the Largest-Sum-Path  
from the root to one of the leaf nodes.  
Modify your source code from WEEK10 and use it as a library for solving the binary tree for largest sum to a leaf.
<br>

```bash
# example
./lab.exe infile
88
```
deadline: next tuesday

