
CC = gcc

ss : main.o 
	$(CC) ss main.o
main.o : main.c
	$(CC) main.c

clean:
	rm ss *.o
