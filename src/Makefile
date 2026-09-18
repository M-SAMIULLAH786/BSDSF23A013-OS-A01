CC = gcc
CFLAGS = -std=c11 -O0 -ggdb -Wall -I../include
PICFLAGS = $(CFLAGS) -fPIC

OBJDIR = ../obj
LIBDIR = ../lib
BINDIR = ../bin

MAIN_OBJ = $(OBJDIR)/main.o
STR_OBJ = $(OBJDIR)/mystrfunctions.o
FILE_OBJ = $(OBJDIR)/myfilefunctions.o

STATIC_LIB = $(LIBDIR)/libmyutils.a
DYNAMIC_LIB = $(LIBDIR)/libmyutils.so

STATIC_TARGET = $(BINDIR)/client_static
DYNAMIC_TARGET = $(BINDIR)/client_dynamic

all: $(STATIC_TARGET) $(DYNAMIC_TARGET)

$(MAIN_OBJ): main.c
	$(CC) $(CFLAGS) -c main.c -o $(MAIN_OBJ)

$(STR_OBJ): mystrfunctions.c ../include/mystrfunctions.h
	$(CC) $(PICFLAGS) -c mystrfunctions.c -o $(STR_OBJ)

$(FILE_OBJ): myfilefunctions.c ../include/myfilefunctions.h
	$(CC) $(PICFLAGS) -c myfilefunctions.c -o $(FILE_OBJ)

$(STATIC_LIB): $(STR_OBJ) $(FILE_OBJ)
	ar rcs $(STATIC_LIB) $(STR_OBJ) $(FILE_OBJ)

$(DYNAMIC_LIB): $(STR_OBJ) $(FILE_OBJ)
	$(CC) -shared -o $(DYNAMIC_LIB) $(STR_OBJ) $(FILE_OBJ)

$(STATIC_TARGET): $(MAIN_OBJ) $(STATIC_LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(STATIC_LIB) -o $(STATIC_TARGET)

$(DYNAMIC_TARGET): $(MAIN_OBJ) $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -L$(LIBDIR) -lmyutils -o $(DYNAMIC_TARGET)

run: $(DYNAMIC_TARGET)
	LD_LIBRARY_PATH=$(LIBDIR) $(DYNAMIC_TARGET)

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(LIBDIR)/libmyutils.a
	rm -f $(LIBDIR)/libmyutils.so
	rm -f $(BINDIR)/client_static
	rm -f $(BINDIR)/client_dynamic

install:
	mkdir -p /usr/local/bin
	mkdir -p /usr/local/share/man/man3
	cp ../bin/client /usr/local/bin/client
	cp ../man/man3/*.3 /usr/local/share/man/man3/
	mandb


.PHONY: all clean run install
