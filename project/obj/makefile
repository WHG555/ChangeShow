
CC = gcc
OBJS = ./obj/

ss: main.o datashow.o smile.o
	$(CC) -o $@ $^ 
	cp ss ..
	ctags -R *
main.o : ../main.c
	$(CC) -c ../main.c 
datashow.o: ../datashow/datashow.c 
	$(CC) -c ../datashow/datashow.c
smile.o: ../smile/smile.c 
	$(CC) -c -std=c99 -Wall ../smile/smile.c -ledit -lm
clean:
	rm -rf ss *.o tags
