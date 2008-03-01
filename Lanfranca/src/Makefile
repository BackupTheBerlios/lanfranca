LIBS=
GPP=g++
CC=gcc
OBJECTS=$(SRCS:.c=.o)
MODIR=Module/

all:
	$(GPP) -c main.cpp module.cpp
	$(GPP) main.o module.o -o test
	rm -rf module.o
	$(CC) -c -shared $(MODIR)plugin.c -o $(MODIR)plugin.o
	$(CC) -shared $(MODIR)plugin.o -o plugin.so

clean:
	rm -rf *.o
	rm -rf test
	rm -rf *.so
	rm -rf $(MODIR)*.o
