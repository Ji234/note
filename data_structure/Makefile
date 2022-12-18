src=$(wildcard *.c ./sub/*.c)
src1=$(wildcard *.cpp)
obj=$(patsubst %.c,bin/%.o,$(src))
obj1=$(patsubst %.cpp,bin/%.o,$(src1))
targets=$(patsubst %.c,bin/%,$(src))
targets1=$(patsubst %.cpp,bin/%,$(src1))
CFLAGS= -Wall -g
CC=gcc
CPP=g++

all:$(targets) $(targets1)

$(obj):bin/%.o:%.c
	  $(CC) $(CFLAGS) -c $< -o $@

$(targets):%:%.o
	$(CC) $^ -o $@


$(obj1):bin/%.o:%.cpp
	  $(CPP) $(CFLAGS) -c $< -o $@
$(targets1):%:%.o
	$(CPP) $^ -o $@

.PHONY: clean

clean:
	rm -rf bin/*
