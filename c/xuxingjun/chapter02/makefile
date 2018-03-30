
# 设置所用的编译器为g++
CC       = g++
# 编译参数
CCFLAGS  = -std=c++0x
# 编译目标：若干可执行文件
OBJECTS  = sizeof.exe \
	bool.exe \
	char.exe escape_char.exe wchar_t.exe \
	short.exe int.exe unsigned.exe long.exe long_long.exe \
	float.exe double.exe long_double.exe \
	extern.exe
# make
all: $(OBJECTS)
# 将源文件编译成中间文件
%.o: %.cc
	$(CC) $(CCFLAGS) -c $< -o $@
# 将中间文件链接成可执行文件
%.exe: %.o
	$(CC) $(CCFLAGS) $< -o $@
extern.exe : ExampleForExtern.o extern.o
	$(CC) $(CCFLAGS) ExampleForExtern.o extern.o -o $@
# make clean：清理各种中间文件
clean:
	rm -rf *.o core *.stackdump
# make clobber：清理可执行文件，并调用make clean
clobber: clean
	rm -rf *.exe
