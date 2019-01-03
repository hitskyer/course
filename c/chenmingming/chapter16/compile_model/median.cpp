//#include "median.h"
#include <vector>
#include <algorithm>
using namespace std;
template <typename T> bool median(const vector<T> &c, T &m)
{
    vector<T> temp(c);
    if(temp.size()%2==0)
        return false;
    sort(temp.begin(),temp.end());
    typename vector<T>::size_type index = temp.size()/2;
    if(temp[index] > temp[index-1] && temp[index] < temp[index+1])
    {
        m = temp[index];
        return true;
    }
    else
        return false;
}
