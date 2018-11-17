#include "CheckoutRecord.h"
#include"Date.h"
#include<vector>
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