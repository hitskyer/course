#include<iostream>
#include<vector>
using namespace std;

vector<int>::iterator findIn(vector<int>:: iterator beg, vector<int>::iterator end, int iv)
{
    while(beg!=end)
    {
        if(*beg==iv)
            break;
        else
            ++beg;
    }
    return beg;
}

int main()
{
    vector<int> ivec;
    int ival;
    cout << "输入元素：" << endl;
    while(cin >> ival)
    {
        ivec.push_back(ival);
        if(cin.get()=='\n')
            break;
    }
    cout << "输入查找的元素: " << endl;
    cin >> ival;
    vector<int>::iterator iter_result;
    iter_result=findIn(ivec.begin(),ivec.end(),ival);
    if(iter_result!=ivec.end())
    {
        cout << "元素被找到了" << endl;
        return 0;
    }
    else
    {
        cout << "元素未找到 " << endl;
        return -1;
    }
}
