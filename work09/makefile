all: dirz.o
	gcc -o dir dirz.o

stats.o: dirzs.c dirz.h
	gcc -c -g dirz.c

run: all
	./dir

clean:
	rm *~
	rm *.o