#ifndef CHECKEDPTR_CHECKEDPTR_H
#define CHECKEDPTR_CHECKEDPTR_H
#include<vector>
#include <stdexcept>
using namespace std;
class CheckedPtr
{
public:
    CheckedPtr(int *b,int *e):beg(b),end(e),curr(b){ if(beg >= end) throw out_of_range("beg >= end");}
    CheckedPtr(const CheckedPtr &c):beg(c.beg),end(c.end),curr(c.curr){ }
    //前置自增自减
    CheckedPtr& operator++();
    CheckedPtr& operator--();
    //后置自增自减
    CheckedPtr operator++(int);
    CheckedPtr operator--(int);
    //下标重载
    int& operator[](const size_t);
    const int& operator[](const size_t)const;
    //解引用*重载
    int& operator*();
    const int& operator*()const;
    //相等操作符
    friend bool operator==(const CheckedPtr &lhs,const CheckedPtr &rhs);
    bool friend operator!=(const CheckedPtr &lhs,const CheckedPtr &rhs);
    //关系操作符
    friend bool operator<(const CheckedPtr &lhs,const CheckedPtr &rhs);
    friend bool operator<=(const CheckedPtr &lhs,const CheckedPtr &rhs);
    friend bool operator>(const CheckedPtr &lhs,const CheckedPtr &rhs);
    friend bool operator>=(const CheckedPtr &lhs,const CheckedPtr &rhs);
    //加减法操作
    friend CheckedPtr operator+(const CheckedPtr &lhs,const size_t n);
    friend CheckedPtr operator-(const CheckedPtr &lhs,const size_t n);
    friend ptrdiff_t operator-(CheckedPtr &lhs,CheckedPtr &rhs);
private:
    int *beg,*end,*curr;
};


#endif //CHECKEDPTR_CHECKEDPTR_H
