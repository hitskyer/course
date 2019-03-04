#include "Item_base.h"
#include "Bulk_item.h"
#include <iostream>
using namespace std;
void func1(Item_base obj){cout << "func1(Item_base obj)" << endl;}
void func2(Item_base &obj){cout << "func2(Item_base &obj)" << endl;}
Item_base func3()
{
    Item_base obj;
    return obj;
}
int main()
{
    Item_base iobj;
    func1(iobj);
    func2(iobj);
    iobj = func3();
    Item_base *p = new Item_base;
    delete p;
    Bulk_item bobj;
    func1(bobj);
    func2(bobj);
    Bulk_item *q = new Bulk_item;
    delete q;
    return 0;
}