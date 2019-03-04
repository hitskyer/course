#ifndef BASE_BULK_BULK_ITEM_H
#define BASE_BULK_BULK_ITEM_H
#include "Item_base.h"
using namespace std;
class Bulk_item:public Item_base
{
public:
    Bulk_item(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0):
                Item_base(book,sales_price), min_qty(qty), discount(disc_rate)
    {
        cout << "Bulk_item(const string&, double,size_t,double)" << endl;
    }
    //net_price()虚函数
    double net_price(size_t cnt) const
    {
        if(cnt >= min_qty)
            return cnt*(1-discount)*price;
    }
    //复制控制成员
    Bulk_item(const Bulk_item &b):Item_base(b),min_qty(b.min_qty),discount(b.discount)
    {
        cout << "Bulk_item(const Bulk_item&)" << endl;
    }
    Bulk_item& operator=(const Bulk_item &rhs)
    {
        if(this != &rhs)
            Item_base::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        cout << "Bulk_item::operator=()" << endl;
        return *this;
    }
    virtual ~Bulk_item()
    {
        cout << "~Bulk_item()" << endl;
    }
private:
    size_t min_qty;
    double discount;
};
#endif //BASE_BULK_BULK_ITEM_H