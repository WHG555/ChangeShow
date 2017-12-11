
CC = gcc
OBJS = ./upload/*

ss: main.o $(OBJS)
	$(CC) -C datashow
	$(CC) -o $@ $^ 
	ctags -R *
main.o : main.c
	$(CC) -c main.c 
clean:
	rm ss *.o tags
