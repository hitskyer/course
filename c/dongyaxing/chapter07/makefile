#设置所有的编译器都为g++
CC	= g++

#编译参数
CCFLAGS = -std=c++0x

#编译目标：若干可执行文件
OBJECTS = eg_3.exe eg_4.exe eg_5.exe eg_6.exe eg_13.exe\
	 eg_14.exe eg_15.exe eg_20.exe eg_27.exe eg_28.exe\
	 eg_30.exe

#make
all : $(OBJECTS)

#将源文件编译成中间文件

%.o : %.cc
	$(CC) $(CCFLAGS) -c $< -o $@

#将中间文件编译成可执行文件
%.exe : %.o
	$(CC) $(CCFLAGS) $< -o $@

#make clean:清理各种中间文件
clean:
	rm -rf *.o core *.stackdump

#make clobber:清理可执行文件，并调用make clean
clobber : clean
	rm -rf *.exe
