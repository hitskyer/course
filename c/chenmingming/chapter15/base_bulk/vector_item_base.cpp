#include "Item_base.h"
#include "Bulk_item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<Item_base*> itemvec;
    string isbn;
    double price, qty, discount;
    cout << "ÊäÈëBulk_item¶ÔÏó£º"<< endl;
    while(cin >> isbn >> price >> qty >> discount)
    {
    	//itemvec.push_back(Bulk_item(isbn,price,qty,discount));
    	Bulk_item *p = new Bulk_item(isbn,price,qty,discount);
    	itemvec.push_back(p);
    }
    double sum = 0.0;
    for(vector<Item_base*>::iterator it = itemvec.begin();
    			it != itemvec.end();++it)
    {
    	sum += (*it)->net_price(100);
    }
    cout << "sum of net_price:" << sum << endl;
    for(vector<Item_base*>::iterator it = itemvec.begin();
    			it != itemvec.end();++it)
    	delete *it;
    return 0;
}