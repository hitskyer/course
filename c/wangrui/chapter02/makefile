
# 设置所用的编译器为g++
CC       = g++
# 编译参数
CCFLAGS  = -std=c++0x
# 编译目标：若干可执行文件
OBJECTS  =  bool.exe  char.exe short.exe int.exe long.exe\
long_double.exe wchar_t.exe Ex2.10.exe Ex2.11.exe Ex2.3.1.exe
	
# make
all: $(OBJECTS)
# 将源文件编译成中间文件
%.o: %.cc
	$(CC) $(CCFLAGS) -c $< -o $@
# 将中间文件链接成可执行文件
%.exe: %.o
	$(CC) $(CCFLAGS) $< -o $@
# make clean：清理各种中间文件
clean:
	rm -rf *.o core *.stackdump
# make clobber：清理可执行文件，并调用make clean
clobber: clean
	rm -rf *.exe
