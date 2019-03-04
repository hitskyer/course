#include"Value_HasPtr.h"
#include <iostream>
using namespace std;
int main()
{
    int i = 42;
    Value_HasPtr p1(i, 42);
    Value_HasPtr p2 = p1;
    cout << p2.get_ptr_val() << endl;
    p1.set_ptr_val(0);
    cout << p2.get_ptr_val() << endl;
    p2.set_ptr_val(8);
    return 0;
}