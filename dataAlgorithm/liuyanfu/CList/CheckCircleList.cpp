#include <iostream>
#include "LinkList.h"
using namespace std;

bool isExitsLoop(const LinkList &L)
{
	ListNode fast = L.GetHeadNode();
	ListNode slow = L.GetHeadNode();
	while(fast && fast->pNext)
	{
		fast = fast->pNext->pNext;
		slow = slow->pNext;
		if(slow == fast)
			break;
	}
	return (fast != NULL) && (fast->pNext != NULL);
}


ListNode FindLoopPort(const LinkList &L)
{
	ListNode fast = L.GetHeadNode();
	ListNode slow = L.GetHeadNode();
	while(fast && fast->pNext)
	{
		fast = fast->pNext->pNext;
		slow = slow->pNext;
		if(fast == slow)
			break;
	}
	if(fast == nullptr || fast->pNext == nullptr)
		return nullptr;
	else
	{
		slow = L.GetHeadNode();
		while(slow != fast)
		{
			fast = fast->pNext;
			slow = slow->pNext;
		}
		return slow;
	}
}




int main()
{
	LinkList ilst;
	ilst.SetLoopPortPos(4);
	for(UINT i = 0; i < 6; ++i)
	{
		for(UINT j = 0; j < i; ++j)
		{
			if(j % 2 == 0)
				ilst.AddHead((j + 2) * (8 - i));
			else
				ilst.AddTail((j + 3) * (8 * i));
		}

		if(!ilst.Empty())
		{
			cout << endl;
			cout << "The list length is : " << ilst.GetLength() << endl;
			cout << "The Head node of list is : " << ilst.GetHeadNode()->data << endl;
			cout << "The Tail node of list is : " << ilst.GetTailNode()->data << endl;
			cout << "The Middle node of list is : " << ilst.GetMidNode()->data << endl;
			ilst.PrintList();
			if(isExitsLoop(ilst))
			{
				cout << "Current list is CircleList and LoopPort is :" << FindLoopPort(ilst)->data << endl;
			}
			else
				cout << "Current list is SingleList and not possess LoopPort " << endl;

		}
		else
		{
			cout << "Current list is null" << endl;
		}
		
	}
	return 0;
}