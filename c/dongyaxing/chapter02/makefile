# 设置所有的编译器 g++ #

CC	= g++
# 编译参数
CCFLAGS = -std=c++0x 

# 编译目标：若干执行文件

OBJECTS =bool.exe char.exe float.exe int.exe long.exe\
	  long_double.exe short.exe wchar_t.exe\
	  2_1.exe\
	  2_3.exe 2_5.exe 2_6.exe 2_7.exe\
	  2_8.exe 2_9.exe 2_10.exe\
	  2_11.exe 2_14.exe 2_19.exe\
	  2_20.exe 2_21.exe\
	  const.cpp enum.cpp reference.cpp typedef.cpp 



# make
all:$(OBJECTS)

#将源文件编译成中间文件
%.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@


%.exe : %.o
	 $(CC) $(CCFLAGS) $< -o $@

# make clean:清理各种中间文件
clean:
	rm -rf *.o core *.stackdump

# make clobber: 清理可执行文件，并调用 make clean
clobber: clean
	rm -rf *.exe
