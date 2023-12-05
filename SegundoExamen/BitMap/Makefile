# Makefile example
#
# Author: CI0118 Lenguajes ensambladores
# Date: 2023/Nov/30
#
# Run "make dev=ASM" to use assembly routines in code
#
# Run "make" to use C++ code
#

CC = gcc
CPP = g++
LD = g++
CCFLAGS = -g -c
CPPFLAGS = -g -c -D$(dev)
LDFLAGS = -g -z noexecstack

all: BitMapTest.out

%.o: %.asm
	nasm -g -f elf64 $<

%.o: %.s
	$(CC) $(CCFLAGS) $<

%.o: %.cc %.h
	$(CPP) $(CPPFLAGS) $<


BitMapTest.out: BitMap.o BitMapTest.o BitMapS.o
	$(LD) $(LDFLAGS) -o BitMapTest.out BitMapTest.o BitMap.o BitMapS.o

clean:
	rm -f *.o *.out

