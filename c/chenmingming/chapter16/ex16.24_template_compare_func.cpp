#include<iostream>
#include<string>
using namespace std;
template <typename T> int compare(const T &v1, const T &v2)
{
    if(v1 < v2) return -1;
    if(v2 < v1) return 1;
    return 0;
}

int main()
{
    short sval = 123;
    int ival = 1024;
    cout << compare(static_cast<int>(sval),ival) << endl;
    cout << compare(sval,static_cast<short>(ival)) << endl;
    cout << compare<short>(sval,ival) << endl;
    cout << compare<int>(sval,ival) << endl;
    cout << compare<string>("mary","mac") << endl;
    cout << compare(static_cast<string>("mary"),static_cast<string>("mac")) << endl;
    cout << compare(string("mary"),string("mac")) << endl;
    return 0;
}