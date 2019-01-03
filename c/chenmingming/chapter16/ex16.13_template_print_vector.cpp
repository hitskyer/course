#include<iostream>
#include<vector>
#include<string>
using namespace std;
// template <typename T> void print(const T &c) //ex16.13
// {
//     typename T::size_type index = 0;
//     while(index != c.size())
//     {
//         cout << c[index] << " ";
//         ++index;
//     }
// }
template <typename T> void print(const T &c)    //ex16.14
{
    typename T::const_iterator it = c.begin();
    while(it != c.end())
    {
        cout << *it << " ";
        ++it;
    }
}
int main()
{
    int ia[] = {1,2,2,4,4,4,7};
    string sa[] = {"this","is","Mary","test","example"};
    vector<int> ivec(ia,ia+7);
    vector<string> svec(sa,sa+5);
    print(ivec);
    cout << endl;
    print(svec);
    return 0;
}