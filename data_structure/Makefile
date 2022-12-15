src=$(wildcard *.c ./sub/*.c)
obj=$(patsubst %.c,bin/%.o,$(src))
targets=$(patsubst %.c,bin/%,$(src))
CFLAGS= -Wall -g
CC=gcc

all:$(targets)

$(obj):bin/%.o:%.c
	  $(CC) $(CFLAGS) -c $< -o $@

$(targets):%:%.o
	$(CC) $^ -o $@

.PHONY: clean

clean:
	rm -rf bin/*
