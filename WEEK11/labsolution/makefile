lab: lab.o bin_max_sum.o 
	gcc -o lab lab.o bin_max_sum.o

lab.o: lab.c bin_max_sum.h
	gcc -c lab.c

bin_max_sum.o: bin_max_sum.c bin_max_sum.h
	gcc -c bin_max_sum.c		

clean: 
	rm lab.exe lab.o bin_max_sum.o
