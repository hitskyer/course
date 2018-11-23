#ifndef SCREEN_H
#define SCREEN_H
#include<iostream>
#include<string>
using namespace std;
class Screen
{
public:
    typedef std::string::size_type index;			//定义序号别名
    Screen():height(0),width(0),cursor(0),contents(""){ }   //默认构造函数
    Screen(index, index, const std::string &);	//声明构造函数
    Screen& display(std::ostream &os);
private:
    std::string contents;	//定义成员变量 内容字符串
    index cursor;			//定义成员变量 光标序号
    index height, width;	//定义成员变量 高，宽
};
#endif
