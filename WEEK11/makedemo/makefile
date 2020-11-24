main: main.o dynamicstack.o 
	gcc -o main main.o dynamicstack.o	# links both files and external libraries

main.o: main.c dynamicstack.h
	gcc -c main.c						# assembles main.c into main.o

dynamicstack.o: dynamicstack.c dynamicstack.h
	gcc -c dynamicstack.c		

clean: 
	rm main.exe main.o dynamicstack.o
