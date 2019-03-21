#include <iostream>
#include <stdio.h>
#include <string>
#include "SingleList.cpp"

using namespace std;

int main()
{
	SingleList<char> clst;
	cout << "\t\t-----------------------------" << endl;
	cout << "\t\tPlease enter a word, I can tell you it is palindrome or not" << endl;
	char ch = cin.get();
	while(ch != '\n')
	{
		clst.AddTail(ch);
		cin.clear();
		ch = cin.get();
	}

	SingleList<char>::ListNode MidNode = clst.GetMidNode();
	SingleList<char>::ListNode TempNode = MidNode->pNext;
	MidNode->pNext = NULL;

	SingleList<char> Backclst;
	while(TempNode)
	{
		Backclst.AddTail(TempNode->data);
		TempNode = TempNode->pNext;
	}
	
	Backclst.ReverseList();
	if(Backclst.IsEmpty())
	{
		cout << "It is palindrome word" << endl;
		return 0;
	}
	SingleList<char>::ListNode p = clst.GetHeadNode(), q = Backclst.GetHeadNode();
	while(p || q)
	{
		if(p->data != q->data)
			break;
		p = p->pNext;
		q = q->pNext;
	}

	if(q == NULL && p == NULL)
		cout << "It is palindrome word" << endl;
	else
		cout << "It is not palindrome word" << endl;
	return 0;
}