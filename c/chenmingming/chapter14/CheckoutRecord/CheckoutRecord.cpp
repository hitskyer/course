#include "CheckoutRecord.h"
#include"Date.h"
#include<vector>
using namespace std;
ostream& operator<<(ostream &out, const CheckoutRecord &c)
{
    out << c.book_id << "\t" << c.title << endl
        << "date borrowed: " << c.date_borrowed << endl
        << "date due: " << c.date_due << endl
        << "borrower: " << c.borrower.first << ", "
                        << c.borrower.second << endl;
    out << "wait list: " << endl;
    for(vector<pair<string,string>*>::const_iterator iter = c.wait_list.begin();
        iter != c.wait_list.end();++iter)
    {
        out << "\t" << (*iter)->first << ", " << (*iter)->second << endl;
    }
    return out;
}
istream& operator>>(istream &in, CheckoutRecord &c)
{
    in >> c.book_id >> c.title
        >> c.date_borrowed >> c.date_due
        >> c.borrower.first >> c.borrower.second;
    if(!in)
    {
        c = CheckoutRecord();
        return in;
    }
    c.wait_list.clear();
    while (in)
    {
        pair<string,string> *ppa = new pair<string,string>;
        in >>  ppa->first >> ppa->second;
        if(!in)
        {
            return in;
        }
        c.wait_list.push_back(ppa);
    }
    return in;
}
CheckoutRecord& CheckoutRecord::operator=(const CheckoutRecord &rhs)
{
    book_id = rhs.book_id;
    title = rhs.title;
    date_borrowed = rhs.date_borrowed;
    date_due = rhs.date_due;
    borrower = rhs.borrower;
    wait_list.clear();
    for(vector<pair<string,string>* >::const_iterator it = rhs.wait_list.begin();
        it != rhs.wait_list.end();++it)
    {
        pair<string,string> *ppa = new pair<string,string>;
        *ppa = **it;
        wait_list.push_back(ppa);
    }
    return *this;
}
//设置新的还书日期
CheckoutRecord& CheckoutRecord::operator=(const Date& new_due)
{
    date_due = new_due;
    return *this;
}
//增加一个预约读者
CheckoutRecord& CheckoutRecord::operator=(const pair<string,string>& newwaiter)
{
    pair<string,string> *ppa = new pair<string,string>;
    *ppa = newwaiter;
    wait_list.push_back(ppa);
    return *this;
}
//下标重载
pair<string,string>& CheckoutRecord::operator[](const vector<pair<string,string>*>::size_type index)
{
    return *wait_list.at(index);
}
const pair<string,string>& CheckoutRecord::operator[](const vector<pair<string,string>*>::size_type index)const
{
    return *wait_list.at(index);
}
//ostream& operator<<(ostream &out, CheckoutRecord &c,vector<pair<string,string>*>::size_type index)
//{
//
//}
//获取读者函数
pair<string,string>& CheckoutRecord::get_waiter(const size_t index)
{
    cout << wait_list[index]->first << " " << wait_list[index]->second << endl;
    return *wait_list[index];
}
const pair<string,string>& CheckoutRecord::get_waiter(const size_t index)const
{
    cout << wait_list[index]->first << " " << wait_list[index]->second << endl;
    return *wait_list[index];
}