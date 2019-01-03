#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template <typename T>
typename T::value_type mostFre(T first, T last)
{
    size_t amount = 0;
    T start = first;
    while(start != last)
    {
        amount++;
        start++;
    }
    typedef std:: vector<typename T::value_type> VecType;
    VecType vec(amount);
    typename VecType::iterator newfirst = vec.begin();
    typename VecType::iterator newlast = vec.end();
    uninitialized_copy(first,last,newfirst);
    sort(newfirst,newlast);
    size_t maxOccu = 0, occu = 0;
    typename VecType::iterator preIter = newfirst;
    typename VecType::iterator maxOccuElemIt = newfirst;
    while(newfirst != newlast)
    {
        if(*newfirst != *preIter)
        {
            if(occu > maxOccu)
            {
                maxOccu = occu;
                maxOccuElemIt = preIter;
            }
            occu = 0;
        }
        ++occu;
        preIter = newfirst;
        ++newfirst;
    }
    if(occu > maxOccu)
    {
        maxOccu = occu;
        maxOccuElemIt = preIter;
    }
    return *maxOccuElemIt;
}


int main()
{
    int ia[] = {1,2,2,4,4,4,7};
    vector<int> ivec(ia,ia+7);
    int s = mostFre(ivec.begin(),ivec.end());
    cout << s << endl;
    return 0;
}