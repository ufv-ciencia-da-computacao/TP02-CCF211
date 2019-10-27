 
all: knapsack clear

knapsack: file.o knapsack.o knapsack_main.o
	gcc knapsack_main.o file.o knapsack.o -o knapsack

file.o: ../../libinterface/file.c
	gcc -c ../../libinterface/file.c -o file.o

knapsack.o: ../../libknapsack/knapsack.c
	gcc -c ../../libknapsack/knapsack.c -o knapsack.o

knapsack_main.o: knapsack_main.c
	gcc -c knapsack_main.c -o knapsack_main.o

clear:
	rm *.o