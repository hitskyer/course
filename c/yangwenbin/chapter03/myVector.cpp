#include <iostream>
using namespace std;
#include <vector>
using std::vector;
#include "myVector.h"
#include <string.h>
#include <ctype.h>

//1.初始化vector
void initVector(){
    vector<int> ivec1;
    vector<int> ivec2(ivec1);
    vector<int> svec(ivec1);
    //包含10个值是-1的元素
    vector<int> ivec4(10,-1);
    vector<string> ivec5(10,"hi");

    vector<string> fvec(10);
    cout << fvec[1] << endl;   //no cout
    cout << ivec4[1] << endl;  //cout -1
}

//2.测试vector的API
void testVectorAPI(){
    //包含10个值是-1的元素
    cout <<"------------------------------------------------------------------------------------" << endl;
    vector<int> ivec4(10,-1);
    vector<int> ivec3(8,10);
    cout << "is empty: " << ivec4.empty() << endl;
    cout << "size value: " << ivec4.size() << endl;
    ivec4.push_back(7);
    cout << "ivec4[n] value: " << ivec4[2] << endl;
    ivec4 =ivec3;
    cout << "ivec4[n] value: " << ivec4[3] << endl;
    if(ivec4 == ivec3){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}

//4. 遍历vector的数据 然后打印
static void printVectorData(vector<string> text){
    string word;
    if(text.empty()){
        cout << "传入的数据异常" << endl;
        return;
    }else{
        for (int i = 0; i!=text.size() ; ++i) {
              word += text[i];
        }
        cout << "word的值是:" << word << endl;
    }
}

//3.测试vector的添加数据
void testVectorAdd(){
    cout <<"------------------------------------------------------------------------------------" << endl;
    cout <<"请输入一个单词:" << endl;
    string word;
    vector<string> text;
    while(cin >> word){
        if(word == "exit"){
            cout << "程序结束" << endl;
            //遍历获取数据
            printVectorData(text);
            break;
        }else{
            cout << word << endl;
            text.push_back(word);
        }
    }
}

//6.遍历的时候将输入的字符串 变为大写 8个一行
 void printVectorDataChange(vector<string> text){
    string word;
    if(text.empty()){
        cout << "传入的数据异常" << endl;
        return;
    }else{
            unsigned int i,j;
            for(i=0;i<text.size();i++)
                for(j=0;j<text[i].size();j++)
                    text[i][j]=toupper(text[i][j]);  //得把toupper的返回值赋给其本身才行
            for(i=0;i<text.size();i++){
                if(i>0 && i % 8 ==0){
                    word += text[i] +" "+"\n";
                }else{
                    word += text[i] +" ";
                }
            }
        }
        cout << "打印的结果为:" << word << endl;
    }


// 5.将一行单词读取到vector中，然后将小写变成大写，然后每隔8个单词换行
void testVectorChage(){
    cout <<"------------------------------------------------------------------------------------" << endl;
    cout <<"请输入一个单词:" << endl;
    string word;
    vector<string> text;
    while(cin >> word){
        if(word == "exit"){
            cout << "程序结束" << endl;
            //遍历获取数据
            printVectorDataChange(text);
            break;
        }else{
            cout << word << endl;
            text.push_back(word);
        }
    }
}





