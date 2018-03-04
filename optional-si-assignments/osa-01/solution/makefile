#*******************************************************************************
# Copyright (c) Judson James, 02.25.2018
# For use with Supplemental Instruction OSA 1, Spring 2018
#*******************************************************************************

GCC = g++
FLAGS = -std=c++11 -Wall -g

osa_01: tester.o array.o
	$(GCC) $(FLAGS) -o osa_01 tester.o array.o

tester.o: tester.cc array.h
	$(GCC) $(FLAGS) -c $^

array.o: array.cc
	$(GCC) $(FLAGS) -c $^

all:
	osa_01

clean:
	rm *.o osa01 *.gch

backup:
	tar -cvf $(USER).osa01.tar *.cc *.h makefile
