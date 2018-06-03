#include <iostream>
#include <string.h>
using namespace std;
#include <iomanip>
using std::setw;
#include "myPoint.h"

//c++的内存地址
void printPointAdress(){
    int var1;
    int var2[10];
    cout << "var1变量的地址是:" << &var1 << endl;
    cout << "var2变量的地址是:" << &var2 << endl;

//    var1变量的地址是:0xffffcbcc
//    var2变量的地址是:0xffffcba0
}

//指针的声明的方式 type是c++支持的基本的数据类型  var-name 是指针变量的名称  * 用于指定这个变量是一个指针
//type *var-name;

//指针的定义
int    *ip;    /* 一个整型的指针 */
double *dp;    /* 一个 double 型的指针 */
float  *fp;    /* 一个浮点型的指针 */
char   *ch;    /* 一个字符型的指针 */

//整型、浮点型、字符型，还是其他的数据类型都是一样的，都是一个代表内存地址的长的十六进制数  不同的是指针所指向的数据类型不同

void pointExample(){
    int var =20;     //实际变量的声明
    int *ip;         //指针变量的声明

    ip =&var;        //在指针变量中存储实际变量的地址
    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针地址中存储的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

//    Value of var variable: 20
//    Address stored in ip variable: 0xffffcbc4
//    Value of *ip variable: 20
}

//递增变量指针，以便顺序访问数组中的每一个元素  对于数组来说是一个常量指针,不可进行递增,而变量指针可以递增
void addPoint(){
    const int MAX =3;
    int  var[MAX] = {10, 100, 200};
    int  *ptr;

    // 将数组的地址放在指针中
    ptr = var;
    for (int i = 0; i < MAX; i++)
    {
        //指针地址
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;

        //指针的值
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;

        // 指针移动到下一个位置 获取到下一个位置数组的地址和值 指针可以移动 数组不行
        ptr++;
    }

//    Address of var[0] = 0xffffcbb4
//    Value of var[0] = 10
//    Address of var[1] = 0xffffcbb8
//    Value of var[1] = 100
//    Address of var[2] = 0xffffcbbc
//    Value of var[2] = 200

}

//c++ 传递指针给函数
void getSeconds(unsigned long *par)
{
    // 获取当前的秒数
    *par = time( NULL );
    return;


//    指针的地址是:0xffffcbe8
//    指针中对应的秒的值是：1526630587
}

// c++ 传递数组作为函数的参数 定义的时候需要把数组参数定义成指针才可以传入
double getAverage(int *arr, int size)
{
    int    i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    avg = double(sum) / size;
    cout << "avg的值为:" << avg << endl;
    return avg;

    //avg的值为:13
}





