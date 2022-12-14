src=$(wildcard *.c ./sub/*.c)
obj=$(patsubst %.c,bin/%.o,$(src))
targets=$(patsubst %.c,bin/%,$(src))
CFLAGS= -Wall  -O3
CC=gcc

all:$(targets)

$(obj):bin/%.o:%.c
	  $(CC) $(CFLAGS) -c $< -o $@

$(targets):%:%.o
	$(CC) $^ -o $@

.PHONY: clean

clean:
	rm -rf bin/*

#编译目标:匹配规则
