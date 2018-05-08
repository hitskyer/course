#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotAssignable"
using std::bitset;
using namespace std;
#include "myBitset.h"

//1.初始化bitset
void initBitset(){
    bitset<32> bitvec;
    bitset<16> bitvec1(0xffff);  //一个字节由两个16进制表示
    bitset<32> bitvec2(0xffff);
    bitset<128> bitvec3(0xffff);

    string strval("1100");
    bitset<32> bitvec4(strval);

    string str("1111111000000001100111");
    bitset<32> bitset5(str,5,4); //1100
    bitset<32> bitset6(str,str.size()-4);  //最后4个值  0111
}

//2.测试API
void testBitsetAPI(){
    string str("1111111000000001100111");
    bitset<32> bitset1(str,5,8); //11000000
    cout << "bitset1是否存在置为1的二进制位?" << bitset1.any() << endl;
    cout << "bitset1不存在置为1的二进制位吗？" << bitset1.none() << endl;
    cout << "bitset1中为1的二进制位的个数？" << bitset1.count() << endl;
    cout << "bitset1中二进制的位数？" << bitset1.size() << endl;
    cout << "bitset1[pos]中的二进制位？" << bitset1[3]<< endl;
    cout << "bitset1中pos处的二进制位为1吗？" << bitset1.test(0) << endl;  //从后面开始的第一位是0
    cout << "bitset1中所有的二进制位设置为1？" << bitset1.set() << endl;
    cout << "bitset1在pos处设置二进制的值为1？" << bitset1.set(4) << endl;
    cout << "bitset1所有的二进制位都设置为0？" << bitset1.reset() << endl;
    cout << "bitset1的pos位置二进制位都设置为0？" << bitset1.reset(5) << endl;
    cout << "bitset1的所有位置的值都取反？" << bitset1.flip() << endl;
    cout << "bitset1的pos位置的值取反？" << bitset1.flip(5) << endl;  //这是从后面开始的  从0开始然后到第五个  设置为0
}

// 3.测试bitset数据遍历  偶数下标设置为1
void testBitsetLoop(){
   bitset<32> bitvec;
    for(int index =0;index!=bitvec.size();index++){
        if(index %2 ==0){
            bitvec[index] =1;
        }else{
            bitvec[index] =0;
        }
    }
    //打印结果
    for(int index =0;index!=bitvec.size();index++){
       cout << bitvec[index] << endl;
    }

}

