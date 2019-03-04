#ifndef TEMPLATE_COUNT_COUNT_H
#define TEMPLATE_COUNT_COUNT_H

#include <vector>
#include <algorithm>
#include <string>
#include <cstddef>
using std::vector;
using std::size_t;
using std::string;
template<typename T>
size_t count(const vector<T> &vec, const vector<T> &sought)
{
    size_t result = 0;
    for(typename vector<T>::const_iterator
            iter = sought.begin(); iter != sought.end(); ++iter)
        result += std::count(vec.begin(),vec.end(),*iter);
    return result;
}
//模板特化
template <>
size_t count<string>(const vector<string> &vec, const vector<string> &sought)
{
    size_t result = 0;
    for(vector<string>::const_iterator
                iter = sought.begin(); iter != sought.end(); ++iter)
        result += std::count(vec.begin(),vec.end(),*iter);
    return result;
}
#endif //TEMPLATE_COUNT_COUNT_H
