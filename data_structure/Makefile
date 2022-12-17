src=$(wildcard *.c ./sub/*.c)
src=$(wildcard *.c ./sub/*.cpp)
obj=$(patsubst %.c,bin/%.o,$(src))
targets=$(patsubst %.c,bin/%,$(src))
CFLAGS= -Wall -g
CC=gcc
CPP=g++

all:$(targets)

$(obj):bin/%.o:%.c
	  $(CC) $(CFLAGS) -c $< -o $@

$(obj):bin/%.o:%.cpp
	  $(CPP) $(CFLAGS) -c $< -o $@

$(targets):%:%.o
	$(CC) $^ -o $@

.PHONY: clean

clean:
	rm -rf bin/*
