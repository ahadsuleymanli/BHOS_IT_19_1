## 2nd LAB ASIGNMENT

## Steps:
***0 Get your ssh key and git commands working***  
It is absolutely necessary for you to get your ssh key and git commands working before next tuesday

***1 Rename your git repository to ASIGNMENTS***  
Go to you github repository -> settings -> rename it and press "Rename"  
***2 Clone your repository and cd into the directory***
```bash
$ git git@github.com:{your repo url}.git 
$ cd {your repo name}
$ git status
```

***3 Create a folder named WEEK2 and add write your c asignment there***  
In your git console or linux console:  
```bash
$ mkdir WEEK2
$ vi WEEK2/asignment.c
```
***4 Windows users should download and install MinGW***  
https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/  
https://www.youtube.com/watch?v=guM4XS43m4I  

***5 compile and check your file*** 
```bash
$ gcc asignment.c
$ ./a.exe
```

***Bonus steps create a .gitignore file***
```bash
$ vi .gitignore
```
```
*.exe
a
"any other files you want git to ignore"
```

***6 create a commit and push it to git***
```bash
$ git add WEEK2/
$ git commit -m "brief description of changes you made"
$ git push origin master
```

### Due date:
Asignment is due Tuesday 29th before first lecture hour