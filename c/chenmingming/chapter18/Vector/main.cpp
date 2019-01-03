#include "Vector.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Vector<int> Ivec;
    for(size_t i = 0; i != 8; ++i)
    {
        Ivec.push_back(i);
        cout << Ivec[i] << "\t";
    }
    cout << endl;
    cout << Ivec.size() << "\t" << Ivec.capacity() << endl;
    Ivec.reserve(50);
    cout << Ivec.size() << "\t" << Ivec.capacity() << endl;
    Ivec.resize(20);
    for(size_t i = 0; i != 20; ++i)
    {
        cout << Ivec[i] << "\t";
    }
    cout << endl;
    cout << Ivec.size() << "\t" << Ivec.capacity() << endl;
    cout << Ivec[2] << "\t" << Ivec[10] << endl;
    int i = 0;
    for(Vector<int>::iterator iter = Ivec.begin();
                iter != Ivec.last(); ++iter)
    {
        *iter = ++i;
        cout << *iter << "\t";
    }
    cout << endl;
    Vector<string> svec;
    string s;
    cout << "enter some strings: " << endl;
    while(cin >> s)
        svec.push_back(s);
    for(size_t i = 0; i != svec.size(); ++i)
        cout << svec[i] << "\t";
    cout << endl;
    cout << svec.size() << "\t" << svec.capacity() << endl;
    svec.reserve(50);
    cout << svec.size() << "\t" << svec.capacity() << endl;
    svec.resize(20);
    for(Vector<string>::iterator iter = svec.begin();
        iter != svec.last(); ++iter)
    {
        cout << *iter << "\t";
    }
    cout << endl;
    cout << svec.size() << "\t" << svec.capacity() << endl;
    cout << svec[2] << "\t" << svec[10] << endl;
    return 0;
}