#ifndef SCREEN_H
#define SCREEN_H
#include<string>
#include<iostream>

class Screen
{
public:
	typedef std::string::size_type index;			//定义序号别名
	Screen(index hgth, index wdth, const std::string &cntnts);	//声明构造函数
	char get() const { return contents[cursor];}	//定义成员函数 get() 返回位置处的字符
	char get(index ht, index wd) const;		//声明成员函数 get(a,b) get重载函数
	index get_cursor() const;						//声明成员函数 get_cursor() 返回index
	Screen& move(index r, index c);					//声明成员函数 move(a,b) 返回screen类引用
	Screen& set(char);								//声明成员函数 set(a) 返回screen类引用
	Screen& display(std::ostream &os);					//声明成员函数 display(输出流) 返回screen类引用
private:
	std::string contents;	//定义成员变量 内容字符串
	index cursor;			//定义成员变量 光标序号
	index height, width;	//定义成员变量 高，宽
};

#endif