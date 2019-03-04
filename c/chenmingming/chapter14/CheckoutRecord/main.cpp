#include"Date.h"
#include"CheckoutRecord.h"
#include <iostream>
using namespace std;
int main()
{
    CheckoutRecord cr,cr1;
    Date date(2020,10,10);
    cin >> cr;
    cout << cr;
    cr1 = cr;
    cr1 = date;
    cr1 = make_pair("chen","baby");
    cout << cr1;
    cout << cr1[0].first << " " << cr1[0].second << endl;
    cr1.get_waiter(1);
    return 0;
}