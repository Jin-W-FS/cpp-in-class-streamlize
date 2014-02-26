CC=g++
CXXFLAGS += -g -O2 -Wall -Werror
# CXXFLAGS += -std=c++0x

all:test

test:test.o

test.o:streamlize.hpp

clean:
	-rm test.o test
