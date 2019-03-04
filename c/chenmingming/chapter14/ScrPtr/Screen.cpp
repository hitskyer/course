#include"Screen.h"
#include<iostream>
#include<string>
using namespace std;

Screen::Screen(index hgth, index wdth, const string &cntnts = " "):
        cursor(0), height(hgth),width(wdth)
{											//定义构造函数 光标位置为0，屏幕尺寸初始化
    contents.assign(hgth*wdth, '*');		//填充文本初始化为hgth*wdth个 空格
    if(!cntnts.empty())
        contents.replace(0,cntnts.size(),cntnts);	//从第0位开始，用输入的字符串替换掉
}

char Screen::get(index r, index c) const	//定义成员函数 get(a,b)
{
    if(!contents.empty() && r > 0 && c > 0 && r <= height && c <= width)
    {
        return contents[(r-1) * width + c - 1];					//返回(r,c)行列处的字符
    }
    else
    {
        cout << "超出屏幕范围！！！" << endl;
    }
    return '!';
}

Screen::index Screen::get_cursor() const	//定义成员函数get_cursor()
{
    return cursor;							//注意返回值类型前加类名！
}

Screen& Screen::move(index r, index c)		//定义成员函数 move(),光标cursor移动到指定位置
{
    index row = r * width;
    cursor = row + c;
    return *this;
}

Screen& Screen::set(char c)					//定义成员函数 set(a)
{
    contents[cursor] = c;					//光标处字符=c
    return *this;
}

Screen& Screen::display(ostream &os)		//定义成员函数 display()
{
    string::size_type index = 0;
    while(index != contents.size())			//把字符按每行宽度个输出
    {
        os << contents[index];
        if((index+1)%width == 0)
        {
            os << '\n';
        }
        ++index;
    }
    return *this;
}