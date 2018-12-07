#ifndef BASE_BULK_ITEM_BASE_H
#define BASE_BULK_ITEM_BASE_H
#include <iostream>
using namespace std;

class Item_base
{
public:
    Item_base(const string &book = "", double sales_price = 0.0):isbn(book),price(sales_price)
    {
        cout << "Item_base(const string&, double)" << endl;
    }
    string book() const
    {
        return isbn;
    }
    virtual double net_price(size_t n) const
    {
        return n*price;
    }
    //复制控制成员
    Item_base(const Item_base &ib):isbn(ib.isbn),price(ib.price)
    {
        cout << "Item_base(const Item_base &)" << endl;
    }
    Item_base& operator=(const Item_base &rhs)
    {
        isbn = rhs.isbn;
        price = rhs.price;
        cout << "Item_base::operator=()" << endl;
        return *this;
    }
    virtual ~Item_base()
    {
        cout << "~Item_base()" << endl;
    }
private:
    string isbn;
protected:
    double price;
};
#endif //BASE_BULK_ITEM_BASE_H
