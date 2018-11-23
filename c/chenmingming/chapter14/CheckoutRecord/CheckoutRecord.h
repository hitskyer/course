#ifndef CHECKOUTRECORD_H
#define CHECKOUTRECORD_H
#include<string>
#include<vector>
#include<iostream>
#include "Date.h"

using namespace std;
class Date;

class wait_list;

class CheckoutRecord
{
public:
    //复制构造
    CheckoutRecord& operator=(const CheckoutRecord &rhs);
    //设置新的还书日期
    CheckoutRecord& operator=(const Date& new_due);
    //增加一个预约读者
    CheckoutRecord& operator=(const pair<string,string>& newwaiter);
    //下标重载
    pair<string,string>& operator[](const vector<pair<string,string>*>::size_type);
    const pair<string,string>& operator[](const vector<pair<string,string>*>::size_type)const;
    //获取等待读者
    pair<string,string>& get_waiter(const size_t index);
    const pair<string,string>& get_waiter(const size_t index)const;
private:
    double book_id;
    std::string title;
    Date date_borrowed,date_due;
    pair<string,string> borrower;
    vector<pair<string,string>* > wait_list;
    friend ostream& operator<<(ostream &out, const CheckoutRecord &c);
    friend istream& operator>>(istream &in, CheckoutRecord &c);
//    friend ostream& operator<<(ostream &out, CheckoutRecord.wait_list[const vector<pair<string,string>*>::size_type] );
};


#endif
