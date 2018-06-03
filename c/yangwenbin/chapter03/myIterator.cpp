#include <string>
#include <iostream>
#include <vector>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotAssignable"
using std::string;
using namespace std;
#include "myIterator.h"

//1.初始化Iterator
void initIterator(){
    vector<int>::iterator iter;
    vector<int> ivec(10,-1);
    //获取开始的元素
//    vector<int>::iterator iter1 =ivec.begin();
//    iter1 =ivec.end();

    cout << "第一种方式遍历数据:" << endl;
    for (int i=0;i!=ivec.size();i++) {
        cout << ivec[i] << endl;
    }
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "第二种方式遍历数据:" << endl;
    for (vector<int>::iterator iter1 =ivec.begin(); iter1!=ivec.end() ; ++iter1) {
         cout << *iter1 << endl;
    }
}


//2.将ivec中的值修改为当前的100倍 练习题
void getIteratorTwo(){
    vector<int> ivec(10,-1);
    int count =0;
    for (vector<int>::iterator iter1 =ivec.begin(); iter1!=ivec.end() ; iter1++) {
        ivec[count] =*iter1 * -100;
        count++;
    }
    cout << "将ivec中的数据增加2倍后打印结果：" << endl;
    for (int i = 0; i!=ivec.size() ; ++i) {
        cout << ivec[i] << endl;
    }
}

//3. 迭代器增量变化  以2开始递增
void getIteratorAddIndex(){
    vector<int> ivec(10,-1);
    for (vector<int>::iterator iter1 =ivec.begin(); iter1!=ivec.end() ; iter1+=2) {
        cout << *iter1 << endl;

    }

}