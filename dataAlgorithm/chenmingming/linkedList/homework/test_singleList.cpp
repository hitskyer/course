//
// Created by mingm on 2019/3/20.
//
#include "singleList.cpp"
#include <iostream>
using namespace std;
int main()
{
    for(int k = 0; k < 5; ++k)
    {
        cout << "------------ test start ----------------" << endl;
        SingleList intList;
        if(intList.IsEmpty())
            cout << "empty list!" << endl;
        cout << intList.GetLength() << " node(s) !" << endl;
        cout << "---------------" << endl;
        cout << "add 0  to " << k-1 << " into list: " << endl;
        for(int j = 0; j < k; ++j)
        {
            intList.AddTail(j);
        }
        cout << intList.GetLength() << " node(s) !" << endl;
        intList.PrintList();
        cout << "------------- reverse list" << endl;
        intList.Reverse();
        intList.PrintList();
        if(intList.GetHeadNode())
        {
            cout << "head node: " << intList.GetHeadNode()->data << endl;
            cout << "tail node: " << intList.GetTailNode()->data << endl;
            cout << "middle node: " << intList.GetMidNode()->data << endl;
        }
        cout << "--------------- addTail " << k << endl;
        intList.AddTail(k);
        intList.PrintList();
        if(intList.posInList(intList.GetMidNode()))
            cout << "midNode in List !" << endl;
        cout << "100 insert at midNode ";
        if(intList.GetMidNode())
            cout << intList.GetMidNode()->data ;
        cout << " front " << endl;
        intList.InsertAt(intList.GetMidNode(),100);
        intList.PrintList();
        cout << "modify head to 99 " << endl;
        intList.ModifyAt(intList.GetHeadNode(),99);
        intList.PrintList();
        cout << "del Tail" << endl;
        intList.RemoveAt(intList.GetTailNode());
        intList.PrintList();
        cout << "del the " << intList.GetLength()-1 << "th node count from end !" << endl;
        intList.RemoveAtBack(intList.GetLength()-1);
        intList.PrintList();
        cout << "address of first " << k-3 << " is ";
        if(intList.Find(k-3))
            cout << intList.Find(k-3) << endl;
        else
            cout << "not exits !" << endl;
    }
    return 0;
}