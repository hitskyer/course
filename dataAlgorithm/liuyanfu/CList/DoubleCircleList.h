#ifndef _DOUBLECIRCLELIST_H
#define _DOUBLECIRCLELIST_H

typedef unsigned int UINT;

template<typename ElmDataType>
struct SNode
{
	ElmDataType data;
	SNode<ElmDataType>* pNext;
	SNode<ElmDataType>* pPrev;
};

template<typename ElmDataType>
class DoubleCircleList
{
	typedef SNode<ElmDataType>* ListNode;
	typedef SNode<ElmDataType>  NodeType;
public:
	DoubleCircleList(void);
	~DoubleCircleList(void);

	bool IsEmpty() const
	{
		return m_ListLen == 0;
	}
	UINT GetLength() const
	{
		return m_ListLen;
	}
	ListNode GetHeadNode() const
	{
		return m_pHead->pNext;
	}
	ListNode GetTailNode() const
	{
		if(IsEmpty())
			return NULL;
		return m_pTail;
	}
	ListNode GetMidNode()  const;
	ListNode GetNode(const int &data) const;

	void AddHead(const int &data);
	void AddTail(const int &data);

	ListNode InsertAt(ListNode pos, const int &data);
	ListNode ModifyAt(ListNode pos, const int &data);
	ListNode RemoveAt(ListNode pos);
	ListNode RemoveAt(UINT nCountBack);
	ListNode Find(const int &data);
	void Erase();

	void PrintList() const;
	void Reverse();

private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_ListLen;

};

#endif//_DOUBLECIRCLELIST_H
