#include <iostream>
#include "constDemo.h"



using  namespace std;

// const在变量中的用法
void testConstVariable(){
    int num = 1;
    int count =10;
    const int a = 1;      //a的值不能被改变
    const int *b = &count;  //b的值不能被改变,这个指针的类型是（const int）const data，not const pointer
    int const *c = &num;  //同上，c的值不能被改变，这个指针的类型是（const int）const data，not const pointer
    int *const d = &num;  //d的地址不能被改变， 这个指针的类型是（const *int）const pointer, not const data

    //a=20;
   // d=&count;  被const修饰以后无法再进行赋值操作
    cout << "*b的值是:" << *b << endl;
}

//const在函数中的用法
const int testConstFunction(){
   // a = 5;     //错误，禁止const函数修改成员变量（error: assignment of member ‘obj::a’ in read-only object）
   // display(); //错误，禁止const函数调用非const成员函数（error: passing ‘const obj’ as ‘this’ argument discards qualifiers）
}

void display(){
    cout << "HI" << endl;
}



