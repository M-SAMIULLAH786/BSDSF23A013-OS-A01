CC = gcc
CFLAGS = -std=c11 -O0 -ggdb -Wall -I../include

TARGET = ../bin/client

all: $(TARGET)

$(TARGET): main.o mystrfunctions.o myfilefunctions.o
	$(CC) $(CFLAGS) main.o mystrfunctions.o myfilefunctions.o -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

mystrfunctions.o: mystrfunctions.c ../include/mystrfunctions.h
	$(CC) $(CFLAGS) -c mystrfunctions.c

myfilefunctions.o: myfilefunctions.c ../include/myfilefunctions.h
	$(CC) $(CFLAGS) -c myfilefunctions.c

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	$(TARGET)

.PHONY: all clean run
