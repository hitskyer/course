#include <iostream>
#include <string.h>
#include "myArray.h"
using namespace std;
#include <iomanip>
using std::setw;

//--------------------------------------------------------------一维数组------------------------------------------------------
//数组的定义的格式 需要注意的是arraySize必须是一个大于0的的整数常量，type 可以是任意有效的 C++ 数据类型
// type arrayName[arraySize];

//一个类型为 double 的包含 10 个元素的数组 balance，声明语句如下：
double balance[10];

//初始化数组  大括号 { }的值的数目不能大于我们在数组声明时指定的元素数目。
double initArray01[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};

// 如果我们在初始化一个数组的时候 省略了大小  那么数组的长度就是数组内元素的数目
double initArray02[] ={100.0,200.0,300.0,500.0,600.0,8.0,10.0};

//为数组中的某个元素赋值 需要写在方法中
//initArray01[1] =20.0;

//通过索引访问数组中的元素 数组的角标是从0开始的
void getArrayValueByIndex(){
    double value =initArray02[1];
    cout << "第" << "2个位置的值是：" << value << endl;
}

//setw() 函数来格式化输出
void arrayExample(int length){
    int n[ length ]; // n 是一个包含 10 个整数的数组

    // 初始化数组元素
    for ( int i = 0; i < length; i++ )
    {
        n[ i ] = i + 100; // 设置元素 i 为 i + 100
    }

    cout << "Element" << setw( 13 ) << "Value" << endl;

    // 输出数组中每个元素的值
    for ( int j = 0; j < length; j++ )
    {
        cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
    }
}


//--------------------------------------------------------------二维数组------------------------------------------------------

//c++ 也支持多维数组 多维数组的定义
// type name[size1][size2]...[sizeN];

//声明创建了一个三维 5 . 10 . 4 整型数组：
int threedim[5][10][4];

//不过一般我们最常用的除了一维数组 就是二维数组 多维的很少用到 二维数组可以理解成由x行,y列组成的一个表格
//type arrayName [ x ][ y ];
//int a[3][4];  定义了一个3行4列的二维数组

//初始化一个二维数组
int a[3][4] = {
        {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
        {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
        {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};

//获取二维数组中的值
void getTwoArrayValue(){
    int value =a[0][1];  //获取索引为0的第一个元素 1
    cout << "二维数组中元素的值为：" << value << endl;
}

//遍历二维数组获取数据
void itatorTwoArrayValue(){
   for (int i=0;i<3;i++){
       for(int j=0;j<4;j++){
           cout << "第"<< i<<"行"<< "第" << j <<"个元素的值是："  <<a[i][j] << endl;
       }
   }
}