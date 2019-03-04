#include "CheckedPtr_Screen.h"
#include<stdexcept>
//解引用操作
Screen& CheckedPtr_Screen::operator*()
{
    if(curr == end)
        throw out_of_range("invalid current pointer");
    return *curr;
}
const Screen& CheckedPtr_Screen::operator*() const
{
    if(curr == end)
        throw out_of_range("invalid current pointer");
    return *curr;
}
//前缀式：返回++ --后的对象；
CheckedPtr_Screen& CheckedPtr_Screen::operator++()
{
    if(curr == end)
        throw out_of_range("increment past the end of CheckedPtr_Screen");
    ++curr;
    return *this;
}
CheckedPtr_Screen& CheckedPtr_Screen::operator--()
{
    if(curr == beg)
        throw out_of_range("increment past the beginning of CheckedPtr_Screen");
    --curr;
    return *this;
}
//后缀式：返回操作前未改变的值
CheckedPtr_Screen CheckedPtr_Screen::operator++(int)
{
    CheckedPtr_Screen ret(*this);
    ++*this;
    return ret;
}
CheckedPtr_Screen CheckedPtr_Screen::operator--(int)
{
    CheckedPtr_Screen ret(*this);
    --*this;
    return ret;
}
//箭头操作符
Screen* CheckedPtr_Screen::operator->()
{
    return curr;
}
const Screen* CheckedPtr_Screen::operator->() const
{
    return curr;
}