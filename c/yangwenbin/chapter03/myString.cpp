#include <string>
#include <iostream>
#include "myString.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "NotAssignable"
using std::string;
using namespace std;

//1.string默认的构造函数是 string s1;

//2.还有其他的构造函数是 string s2(s1);  string s3("value")  string s4(n,'c')

//3.测试字符串输入
void testInputString(){
    string s;
    cout << "请输入一个名字:" << endl;
    cin >> s;
    cout << "您输入的名字为:" << s << endl;
}

//4.测试读取一行
void testGetLine(){
    cout <<"------------------------------------------------------------------------------------" << endl;
    cout << "请输入字符串,输入exit结束:";
   string line;
   while (getline(cin,line)){
       if(line == "exit"){
           cout << "结束程序" << endl;
           return;
       }
       cout << line << endl;
   }

}

//5. 测试string的api
void testStringAPI(){
    cout <<"------------------------------------------------------------------------------------"  << endl;
    string s1 ="abcd";
    string s2 ="efg";
    string st("The expense of spirit");
    cout << "The size of: " << st << "is: " << st.size() << endl;
    cout << "is empty: " << st.empty() << endl;
    cout << "st[n] value: " << st[2] << endl;
    cout << "s1+s2 value:" <<  s1+s2 << endl;
    s1 =s2;
    cout << "s1=s2 value: " << s1 << endl;
    if(s1 ==s2){
        cout << "s1==s2 value: " << "true" << endl;
    }else{
        cout << "s1==s2 value: " << "false" << endl;
    }
}

//6. 测试cctype中的函数
void testCctypeFunction(){
    cout <<"------------------------------------------------------------------------------------" << endl;
    string s("Hello World!!!");
    int countBD =0;
    int countZM =0;
    for(int index =0;index!=s.size();index++){
        if(ispunct(s[index])){
            countBD++;
        }
        if(isalpha(s[index])){
            countZM++;
        }
    }
    cout << "标点符号的数量是:" << countBD << endl;
    cout << "字母的数量是:" << countZM << endl;
}

// 7.键盘输入两个字符串比较大小
void testInputStrCompare(){
    cout <<"------------------------------------------------------------------------------------" << endl;
    string s1;
    string s2;
    cout << "请输入第一个字符串:" << endl;
    cin >> s1;
    cout << "请输入第二个字符串:" << endl;
    cin >> s2;
    if(s1 == s2){
        cout << "输入的两个字符串相等" << endl;
    }else if(s1.size() > s2.size()){
        cout << "输入的两个字符串不相等,第一个字符串长度大于第二个" << endl;
    }else{
        cout << "输入的两个字符串不相等,第一个字符串长度小于第二个" << endl;
    }

}

//8. 去掉标点符号
void testReplace(){
    cout <<"------------------------------------------------------------------------------------" << endl;
    string s1;
    cout << "请输入一个字符串,请带上标点符号:" << endl;
    cin >> s1;
    if(!s1.empty()){
        for(int index =0;index!=s1.size();index++){
            if(!isgraph(s1[index])){
                s1[index] =' ';
            }
            if(ispunct(s1[index])){
                s1[index] =' ';
            }
        }
    }else{
        cout << "输入的字符串的值为null:"<< endl;
    }

    cout << "替换标点符号的字符串的值是:" << s1 << endl;
}


