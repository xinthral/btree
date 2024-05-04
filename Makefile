#/**************************************
# Author: Jesse Hassell
# Due Date: 10/03/2022
# Purpose: Make file to manage the different components of this
# build and be able to compile them individually.
#**************************************/

# the compiler: gcc for C programs, g++ for C++ programs
CC = g++

# Windows Variants
ifeq ($(OS), Windows_NT)
RM=del
endif

# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
# compiler flags:
#  -g       - adds debugging information to the executable file
#  -Wall    - is used to turn on most compiler warnings
#  -Wextra  - turns on extra compiler checks unchecked by -Wall
#  -O       - optimization level (ie -O3)
#  -std     - compile with version compatibility
#  -no-pie  - do not produce a position-independent executable
#  -fPIC    - Format position-independent code
# Standard Compiler Options
CFLAGS = -g -Wno-format -Wno-sign-compare

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++20

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# find *.cpp files and make a list of *.o files
# SOURCES := $(patsubst %.cpp,%.o, $(wildcard *.cpp))

# The build target
# EXECUTABLE = main
TREE = xtree
MOD1 = xnode

# Compile Full porgram
btree: $(MOD1).o $(TREE).o
	$(CC) $(CXFLAGS) $^ -o $@.exe

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c $< -o $@

clean:
	$(RM) *.o *.exe