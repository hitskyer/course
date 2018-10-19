#include<cstring>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string str("first,middle,last"),str1;
    string::reverse_iterator rcomma = find(str.rbegin(),str.rend(),',');
    cout << string(str.rbegin(),rcomma) << endl;
    cout << string(rcomma.base(),str.end()) << endl;
    return 0;
}