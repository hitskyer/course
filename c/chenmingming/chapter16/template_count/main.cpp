#include <iostream>
#include "count.h"
using namespace std;
int main()
{
    double da[] = {2.1, 2.2, 2.3, 2.4, 2.3, 2.8};
    double dsa[] = {2.3, 2.4};
    int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2};
    int isa[] = {2, 4, 10, 9};
    char ca[] = {'a', 'b', 'o', 'a', 'r', 'd'};
    char csa[] = {'a', 'b'};
    string sa[] = {"many", "much", "good", "bad", "large", "small"};
    string ssa[] = {"many", "large", "what"};
    vector<double> dvec(da,da+6);
    vector<double> dsought(dsa,dsa+2);
    vector<int> ivec(ia,ia+10);
    vector<int> isought(isa,isa+4);
    vector<char> cvec(ca,ca+6);
    vector<char> csought(csa,csa+2);
    vector<string> svec(sa,sa+6);
    vector<string> ssought(ssa,ssa+3);

    cout << count(dvec,dsought) << endl;
    cout << count(ivec,isought) << endl;
    cout << count(cvec,csought) << endl;
    cout << count(svec,ssought) << endl;
    return 0;
}