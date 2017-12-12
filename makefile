ss: main.o  
	make -C obj
clean:
	find . -name "*.o" | xargs rm -vf
	find . -name "ss" | xargs rm -vf
	ctags -R *
