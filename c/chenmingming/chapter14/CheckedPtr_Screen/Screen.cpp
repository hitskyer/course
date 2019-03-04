#include "Screen.h"
Screen::Screen(index hgth, index wdth, const string &cntnts = " ")
{
    //定义构造函数 光标位置为0，屏幕尺寸初始化
    cursor=0; height=hgth; width=wdth;
    contents.assign(hgth*wdth, '*');		//填充文本初始化为hgth*wdth个 空格
    if(!cntnts.empty())
        contents.replace(0,cntnts.size(),cntnts);	//从第0位开始，用输入的字符串替换掉
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
    os << std::endl;
    return *this;
}