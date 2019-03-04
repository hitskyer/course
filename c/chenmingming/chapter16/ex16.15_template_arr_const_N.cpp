#include<cstddef>
#include<iostream>
using namespace std;
template <typename T, std::size_t n> std::size_t arrsize(const T (&arr)[n])
{
    cout << "arr have ? elems: " << n << endl;
    return n;
}
template <typename T, std::size_t n> void print(const T (&arr)[n])
{
    for(std::size_t i = 0; i != n; ++i)
        cout << arr[i] << endl;
}

int main()
{
    int ia[] = {1,2,2,4,4,4,7};
    string sa[] = {"this","is","Mary","test","example"};
    arrsize(ia);
    arrsize(sa);
    print(ia);
    print(sa);
    return 0;
}