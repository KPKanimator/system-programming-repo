# Makefile for hello

hello: main.o pr2.o
	cc -o hello main.o pr2.o

hello.о: main.c
	cc -c main.c

pr2.o: pr2.c
	cc -c pr2.c

clean:
	rm -f *.o
	rm -f hello
