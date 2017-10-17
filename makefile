
CC = gcc

ss: main.o datashow.o
	$(CC) -o ss main.o datashow.o
main.o : main.c
	$(CC) -c main.c
datashow.o : datashow.c
	$(CC) -c datashow.c

clean:
	rm ss *.o
