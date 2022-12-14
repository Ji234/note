src=$(wildcard *.c ./sub/*.c)
obj=$(patsubst %.c,%.o,$(src))
targets=$(patsubst %.c,%,$(src))
CFLAGS= -Wall  -O3
CC=gcc

all:$(targets)
	#编译目标:匹配规则
$(targets):%:%.o
	$(CC) $^ -o $@
	cp $@ bin/

.PHONY: clean cleano 

clean:
	rm -rf bin/*
	rm -rf $(targets)
	rm -rf $(obj)

