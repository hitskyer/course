#ifndef CHECKOUTRECORD_DATE_H
#define CHECKOUTRECORD_DATE_H
#include <iosfwd>
using namespace std;
class Date
{
private:
    int year,month,day;
public:
    Date():year(0),month(0),day(0){ }
    Date(int y,int m,int d);
    Date(const Date &date):year(date.year),month(date.month),day(date.day){ }
    Date& operator=(const Date &date);
    ~Date(){ }
    friend istream& operator>>(istream &in,Date &date);
    friend ostream& operator<<(ostream &out,const Date &date);
};
#endif //CHECKOUTRECORD_DATE_H
