#设置所有编译器都为g++
CC	=g++

#编译参数
CCFLAGS = -std=c++0x

#编译目标文件
OBJECTS = eg_3.exe eg_9.exe eg_16.exe write.exe read.exe

#make
all : $(OBJECTS)

#将源文件编译成中间文件

%.o : %.cc
	$(CC) $(CCFLAGS) -c $< -o $@

#将中间文件编译成可执行文件
%.exe : %.o
	$(CC) $(CCFALGS) $< -o $@

#make clean: 清理各种中间文件
clean:
	rm -rf *.o core *.stackdump

#make clobber:清理可执行文件，并调用make clean
clobber: clean
	rm -rf *.exe
