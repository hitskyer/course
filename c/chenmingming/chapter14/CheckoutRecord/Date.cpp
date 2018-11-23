#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int y, int m, int d):year(y),month(m),day(d) { }
Date& Date::operator=(const Date &date)
{
    year = date.year;
    month = date.month;
    day = date.day;
    return *this;
}
istream& operator>>(istream &in, Date &date)
{
    int y,m,d;
    cout << "enter year month day: " << endl;
    in >> y >> m >> d;
    date = Date(y,m,d);
    return in;
}
ostream& operator<<(ostream &out, const Date &date)
{
    out << date.year << "-" << date.month << "-" << date.day << endl;
    return out;
}
