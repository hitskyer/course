在编译我们写好的c++的代码的时候，编译的顺序是：
    1.先将所有的cpp文件编译成.o文件，因为我的代码最后在调用都是在main.cpp中。
    2.执行命令g++ main.cpp -o main  ./myArray.o ./myPoint.o ./myCString.o做链接,这样就会出现一个可执行的main程序,编译成功
    3.然后./main就可以出现我们想要的结果。
