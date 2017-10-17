
CC = gcc

ss: main.o 
	$(CC) -o ss main.o
main.o : main.c
	$(CC) -c main.c

clean:
	rm ss *.o
