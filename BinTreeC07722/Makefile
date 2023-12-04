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
CPPFLAGS = -g -D$(dev)
LDFLAGS = -g -z noexecstack

all: BinTree.out

%.o: %.asm
	nasm -g -f elf64 $<

%.o: %.s
	$(CC) $(CCFLAGS) $<

%.o: %.cc %.h
	$(CC) $(CCFLAGS) $<


BinTree.out: BinNode.o BinTree.o BinTreeS.o BinTreeTest.o
	$(LD) $(LDFLAGS) -o BinTree.out BinNode.o BinTree.o BinTreeTest.o BinTreeS.o

clean:
	rm -f *.o *.out

