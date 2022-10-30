CC=gcc
CFLAGS= -Wall
LDFLAGS=
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
EXEC=choleski

all: $(EXEC)

$(EXEC): fonctionUtile.o
	$(CC) -o $@ fonctionUtile.o $(LDFLAGS) -lm

choleski.o: fonctionUtile.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
