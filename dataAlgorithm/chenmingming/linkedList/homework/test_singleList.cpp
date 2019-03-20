//
// Created by mingm on 2019/3/20.
//
#include "singleList.cpp"
#include <iostream>
using namespace std;
int main()
{
    int num = 100;
    for(int k = 0; k < 5; ++k)
    {
        cout << "-----------------------------" << endl;
        SingleList intList;
        if(intList.IsEmpty())
            cout << "empty list!" << endl;
        cout << intList.GetLength() << " node(s) !" << endl;
        for(int j = 0; j < k; ++j)
        {
            intList.AddTail(j);
        }
        cout << intList.GetLength() << " node(s) !" << endl;
        intList.PrintList();
        intList.Reverse();
        intList.PrintList();
        intList.GetHeadNode();
        intList.GetTailNode();
        intList.GetMidNode();
        intList.AddTail(k);
        intList.posInList(intList.GetMidNode());
        intList.InsertAt(intList.GetMidNode(),100);
        intList.ModifyAt(intList.GetHeadNode(),99);
        intList.RemoveAt(intList.GetTailNode());
        intList.RemoveAtBack(intList.GetLength()-1);
        intList.Find(k);
        intList.PrintList();
    }
    return 0;
}

