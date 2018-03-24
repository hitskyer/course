# executable files for this directory
CC = g++
CCFLAGS = -std=c++0x

OBJECTS =  emotion.exe for4ap_with_step.exe cout_cerr_clog.exe div4one.exe \
	 main.exe multi4one.exe sub4one.exe sum4one.exe sum4one2.exe


all :$(OBJECTS)

%.o : %.cc
	$(CC) $(CCFLAGS) -c $< -o $@
%.exe : %.o
	$(CC) $(CCFLAGS) $< -o $@
clean:
	rm -rf *.out core *.stackdump
clobber : clean
	rm -rf *.exe
# tells make to use the file "GNU_makefile_template", which
# defines general rules for making .o and .exe files

