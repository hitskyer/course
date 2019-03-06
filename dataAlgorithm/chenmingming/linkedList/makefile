# executable files for this directory
OBJECTS = main_single_linkedlist.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
#include .
CC = g++
CCFLAGS = -std=c++0x -I..
LOCFLAGS =
all: $(OBJECTS) 
%.o: %.cc 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -c $< -o $@
%.exe: %.o 
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $@
clean:
	rm -rf *.o core *.stackdump
clobber: clean
	rm -rf *.exe 

main_single_linkedlist.exe: single_linkedlist.h
