CC = gcc
CFLAGS = -Wall -g

all: StrList

StrList: main.o StrList.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c StrList.h
	$(CC) $(CFLAGS) -c $<

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o StrList

.PHONY: clean all