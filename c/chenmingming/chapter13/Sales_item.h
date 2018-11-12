#ifndef SALES_ITEM_H
#define SALES_ITEM_H
class Sales_item
{
public:
	Sales_item& operator=(const Sales_item&);
};
#endif

Sales_item& Sales_item::operator=(const Sales_item &rhs)
{
	isbn = rhs.isbn;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}