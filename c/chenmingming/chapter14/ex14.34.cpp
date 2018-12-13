#include <iostream> //ex14.34
#include <vector>
#include <algorithm>
using namespace std;

class EQ_cls
{
public:
    EQ_cls(int val = 0):spValue(val){ }
    bool operator()(const int &val)
    {
        return val == spValue;
    }
private:
    int spValue;
};

int main()
{
    vector<int> ivec;
    int val;
    cout << "enter numbers: " << endl;
    while(cin >> val)
        ivec.push_back(val);
    cin.clear();
    int replaceVal,newVal;
    cout << "enter a value that be replaced: " << endl;
    cin >> replaceVal;
    cout << "enter a new value: " << endl;
    cin >> newVal;
    vector<int>::iterator iter;
    replace_if(ivec.begin(),ivec.end(),EQ_cls(replaceVal),newVal);
    cout << "new vector is " << endl;
    for(vector<int>::iterator iter = ivec.begin();iter != ivec.end();++iter)
        cout << *iter << " ";
    return 0;
}