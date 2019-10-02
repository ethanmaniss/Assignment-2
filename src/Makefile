# sample Makefile for CPSC 350
# assumes the following directory hierarchy:
# Assignment X
# 		src
# 			include

# this Makefile goes in the src directory

# change this to correct assignment number
EXECUTABLE := Assignment2

# the source files to be built
SOURCES := *.cpp

# stuff you don't need to worry about
INCLUDES := -I ../include
EXT := out
CC := g++

all:
    $(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;
	find . -type f -name "*.out" -exec rm '{}' \;
	find . -type f -name "*.gch" -exec rm '{}' \;

# this line required by make - don't delete
