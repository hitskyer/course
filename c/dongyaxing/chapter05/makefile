#设置所有的编译器都为g++
CC	=g++
#编译参数
CCFLAGS = -std=c++0x
#编译目标：若干可执行文件

OBJECTS =eg_15.exe eg_18.exe eg_21.exe eg_24.exe

# make
all:$(OBJECTS)
#将源文件编译成中间文件
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@
#将源文件编译成中间文件
%.exe: %.o
	$(CC) $(CCFLAGS) $< -o $@
#make clean :清理各种中间文件
clean:
	rm -rf *.o core *.stackdump
#make clobber:清理可执行文件，并调用make clean
clobber: clean
	rm -rf *.exe
