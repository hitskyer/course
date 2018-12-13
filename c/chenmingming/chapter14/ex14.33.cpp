#include <iostream> //ex14.33
#include <vector>
#include <algorithm>
using namespace std;

class GT_cls
{
public:
    GT_cls(int val = 0):bound(val){ }
    bool operator()(const int &val)
    {
        return val > bound;
    }
private:
    int bound;
};

int main()
{
    vector<int> ivec;
    int val;
    cout << "enter numbers: " << endl;
    while(cin >> val)
        ivec.push_back(val);
    cin.clear();
    int spval;
    cout << "enter a specified value: " << endl;
    cin >> spval;
    vector<int>::iterator iter;
    iter = find_if(ivec.begin(),ivec.end(),GT_cls(spval));
    if(iter != ivec.end())
        cout << "the first element that is larger than "
            << spval << "：" << *iter << endl;
    else
        cout << "no element that is larger than " << spval << endl;
    return 0;
}