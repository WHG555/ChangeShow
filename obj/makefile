
CC = gcc
OBJS = ./obj/

ss: main.o datashow.o 
	$(CC) -o $@ $^ 
	cp ss ..
	ctags -R *
main.o : ../main.c
	$(CC) -c ../main.c 
datashow.o: ../datashow/datashow.c 
	$(CC) -c ../datashow/datashow.c
clean:
	rm -rf ss *.o tags
