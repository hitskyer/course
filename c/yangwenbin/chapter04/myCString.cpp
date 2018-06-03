#include <iostream>
#include <string.h>
using namespace std;
#include <iomanip>
using std::setw;
#include "myCString.h"

//c风格字符串  风格的字符串起源于 C 语言 并在c++中得到了继承和支持，字符串实际上是使用字符null字符‘\0’终止的一维字符数组。
//所以他要比实际的字符要多一个结尾的‘\0’,例如Hello
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char greetingStr[] = "Hello";

//其实我们不需要把 null 字符放在字符串常量的末尾。C++ 编译器会在初始化数组时，自动把 '\0' 放在字符串的末尾。

void printStr(){
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

    cout << "Greeting message: ";
    cout << greeting << endl;
}

/**
1.strcpy(s1, s2);
复制字符串 s2 到字符串 s1。
2	strcat(s1, s2);
连接字符串 s2 到字符串 s1 的末尾。
3	strlen(s1);
返回字符串 s1 的长度。
4	strcmp(s1, s2);
如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
5	strchr(s1, ch);
返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
6	strstr(s1, s2);
返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
 * */

void testStringApi(){
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    int  len ;

    // 复制 str1 到 str3
    strcpy( str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;

    //连接字符串 s2 到字符串 s1 的末尾。
    strcat( str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;

    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;

    //如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
    cout << "strcmp(str1,str2) : " << strcmp(str1,str2) << endl;

}

//C++ 标准库提供了 string 类类型，支持上述所有的操作
void testStringMethod(){
    string str1 ="Hello";
    string str2 ="World";
    string str3;
    int  len ;

    // 复制 str1 到 str3
    str3 = str1;

    //连接字符串 s2 到字符串 s1 的末尾。
    str1 = str1 + str2;
    cout << "连接后的字符串为" << str1 << endl;

    // 连接后，str1 的总长度
    cout << "长度为:" << str1.length() << endl;

    //如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。
    if(str1 ==str2){
        cout << "str1 == str2" << "返回值为: 0" << endl;
    } else if(str1>str2){
        cout << "str1 > str2" << "返回值为: 10" << endl;
    }else{
        cout << "str1 < str2" << "返回值为: -5" << endl;
    }

}


