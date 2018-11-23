#include "CheckedPtr.h"
#include <stdexcept>

using namespace std;
//前置自增自减
CheckedPtr& CheckedPtr::operator++()
{
    if(curr == end)
        throw out_of_range("past the end of CheckedPtr");
    ++curr;
    return *this;
}
CheckedPtr& CheckedPtr::operator--()
{
    if(curr == end)
        throw out_of_range("past the begin of CheckedPtr");
    --curr;
    return *this;
}

//后置自增自减
CheckedPtr CheckedPtr::operator++(int)
{
    CheckedPtr ret(*this);
    ++*this;
    return ret;
}
CheckedPtr CheckedPtr::operator--(int)
{
    CheckedPtr ret(*this);
    --*this;
    return ret;
}

//下标重载
int& CheckedPtr::operator[](const size_t index)
{
    if(beg+index >= end || beg+index < beg)
        throw out_of_range("invalid index");
    return *(beg+index);
}
const int& CheckedPtr::operator[](const size_t index)const
{
    if(beg+index >= end || beg+index < beg)
        throw out_of_range("invalid index");
    return *(beg+index);
}
//解引用重载
int& CheckedPtr::operator*()
{
    if(curr==end)
        throw out_of_range("invalid curr pointer");
    return *curr;
}
const int& CheckedPtr::operator*()const
{
    if(curr==end)
        throw out_of_range("invalid curr pointer");
    return *curr;
}
//相等操作符
bool operator==(const CheckedPtr &lhs,const CheckedPtr &rhs)
{
    return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr == rhs.curr;
}
bool operator!=(const CheckedPtr &lhs,const CheckedPtr &rhs)
{
    return !(lhs == rhs);
}
//关系操作符
bool operator<(const CheckedPtr &lhs,const CheckedPtr &rhs)
{
    return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr < rhs.curr;
}
bool operator<=(const CheckedPtr &lhs,const CheckedPtr &rhs)
{
    return !(lhs > rhs);
}
bool operator>(const CheckedPtr &lhs,const CheckedPtr &rhs)
{
    return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr > rhs.curr;
}
bool operator>=(const CheckedPtr &lhs,const CheckedPtr &rhs)
{
    return !(lhs < rhs);
}
//加减法操作
CheckedPtr operator+(const CheckedPtr &lhs,const size_t n)
{
    CheckedPtr temp(lhs);
    temp.curr += n;
    if(temp.curr > temp.end)
        throw out_of_range("too large n");
    return temp;
}
CheckedPtr operator-(const CheckedPtr &lhs,const size_t n)
{
    CheckedPtr temp(lhs);
    temp.curr -= n;
    if(temp.curr < temp.beg)
        throw out_of_range("too large n");
    return temp;
}
ptrdiff_t operator-(CheckedPtr &lhs,CheckedPtr &rhs)
{
    if(!(lhs.beg == rhs.beg && lhs.end == rhs.end))
        throw out_of_range("can't substract");
    return lhs.curr - rhs.curr;
}