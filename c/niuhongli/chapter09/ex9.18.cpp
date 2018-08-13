#include<iostream>
#include<list>
#include<deque>
#include<string>
using namespace std;

int main()
{
    list<int> ilist;
    //输入元素
    int ival;
    deque<int> evenDeq, OddDeq;
    cout << "Please enter integer to list:" << endl;
    while(cin >> ival)
    {
        ilist.push_back(ival);
        if(cin.get()=='\n')
            break;
    }
    //选择元素进入不同的deque
    for(list<int>::iterator iter=ilist.begin();iter!=ilist.end();++iter)
    {
        if(*iter% 2!=0)
            OddDeq.push_back(*iter);
        else
            evenDeq.push_back(*iter);
    }
    // 输出元素
    cout << "Element in Odd deque:" << endl;
    for(deque<int>::iterator iter=OddDeq.begin();iter!=OddDeq.end();++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "Element in Even deque:" << endl;
    for(deque<int>::iterator iter=evenDeq.begin();iter!=evenDeq.end();++iter)
        cout << *iter << " ";
    return 0;
}

