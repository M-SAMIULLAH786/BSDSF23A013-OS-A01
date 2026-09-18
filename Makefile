CC = gcc
CFLAGS = -std=c11 -O0 -ggdb -Wall

all: build

build:
	$(MAKE) -C src

run:
	$(MAKE) -C src run

clean:
	$(MAKE) -C src clean

.PHONY: all build run clean
