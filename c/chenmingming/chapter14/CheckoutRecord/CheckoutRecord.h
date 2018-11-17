#ifndef CHECKOUTRECORD_H
#define CHECKOUTRECORD_H
#include<string>
#include<vector>
#include<iostream>
#include "Date.h"

using namespace std;
class Date;
class CheckoutRecord
{
public:
    //
private:
    double book_id;
    std::string title;
    Date date_borrowed,date_due;
    pair<string,string> borrower;
    vector<pair<string,string>* > wait_list;
    friend ostream& operator<<(ostream &out, const CheckoutRecord &c);
    friend istream& operator>>(istream &in, CheckoutRecord &c);
};


#endif
