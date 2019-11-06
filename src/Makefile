 
all: main clear

main: file.o knapsack.o main.o
	gcc main.o file.o knapsack.o -o main

file.o: libinterface/file.c
	gcc -c libinterface/file.c -o file.o

knapsack.o: libknapsack/knapsack.c
	gcc -c libknapsack/knapsack.c -o knapsack.o

main.o: main.c
	gcc -c main.c -o main.o

clear:
	del *.o
