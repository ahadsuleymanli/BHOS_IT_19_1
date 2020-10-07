## Asignment
***Given a 2D maze made out of a string, find the path to the '\*' character, only vertical and horizontal movements are allowed***  
***The solution should look like this***
```bash
"..##############"
"#.    #.....####"
"#.####*.###.####"
"#....######.####"
"####.# ####.####"
"#   .# ####.####"
"####.# ####.####"
"####........####"
"################"
```
### Code:  
```c
#include <stdio.h>

void printMaze(char **maze, const int HT, const int WD); // prints the maze

int solveMaze(char **maze, const int HT, const int WD, int y, int x); // draws a path to the exit on the maze string

int main(){
    char mazeStr[] ="  ##############"
		            "#     #     ####"
		            "# ####* ### ####"
		            "#    ###### ####"
		            "#### # #### ####"
		            "#    # #### ####"
		            "#### # #### ####"
		            "####        ####"
		            "################";
    const int HT = 9;
    const int WD = 16;
    char *maze[HT];
    char **position = maze;

    for (int i=0; i<HT ; i++)		// filling the 2D char array
	maze[i]=&mazeStr[i*WD];
    
    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);
   
    return 0;
}


int solveMaze(char **maze, const int HT, const int WD, int y, int x){
    
    // solve recursively
    // however you might want to mark wrong paths with some other character
    // your functions should be able to solve other such mazes

}


void printMaze(char **maze, const int HT, const int WD){
    for (int i=0; i<HT ; i++){
	for(int j=0; j<WD-1; j++)
	  printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
    }
}




```

### Due date:  
***Sunday 18th***