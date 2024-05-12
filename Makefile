#/**************************************
# Author: Jesse Hassell
# Due Date: 10/03/2022
# Purpose: Make file to manage the different components of this
# build and be able to compile them individually.
#**************************************/

# the compiler: gcc for C programs, g++ for C++ programs
CC = g++
SEPR=/

# Windows Variants
ifeq ($(OS), Windows_NT)
RM=del
SEPR=\\

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
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-conversion-null -Wno-return-type

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++20

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# The build target
EXEC = run
MOD1 = xtree

# find *.cpp files and make a list of *.o files
# SOURCES := $(patsubst %.cpp,%.o, $(wildcard *.cpp))
CORE := core
CORESRC := $(patsubst $(CORE)/%.cpp, $(CORE)/%.o, $(wildcard $(CORE)/*.cpp))
LNCH := launcher
LNCHSRC := $(patsubst $(LNCH)/%.cpp, $(LNCH)/%.o, $(wildcard $(LNCH)/*.cpp))
TEST := test
TESTSRC := $(patsubst $(TEST)/%.cpp, $(TEST)/%.o, $(wildcard $(TEST)/*.cpp))

# Compile Full porgram
program: $(CORESRC) $(LNCHSRC)
	$(CC) $(CXFLAGS) $^ -o $(EXEC).exe

test: $(CORESRC) $(TESTSRC)
	$(CC) $(CXFLAGS) $^ -o $(EXEC).exe

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp
	$(CC) $(CXFLAGS) -c $< -o $@

clean:
	$(MAKE) cleancore
	$(MAKE) cleanlnch
	$(MAKE) cleantest
	$(RM) *.exe

cleancore:
	$(RM) $(CORE)$(SEPR)*.o

cleanlnch:
	$(RM) $(LNCH)$(SEPR)*.o

cleantest:
	$(RM) $(TEST)$(SEPR)*.o