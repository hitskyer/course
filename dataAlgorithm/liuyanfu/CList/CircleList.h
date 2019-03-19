#ifndef _CIRCLELIST_H
#define _CIRCLELIST_H


typedef unsigned int UINT;
template <typename ElmDataType>
struct SNode
{
	ElmDataType data;
	SNode* pNext;
};

template <typename ElmDataType>
class CCircleList
{
	typedef SNode<ElmDataType>* ListNode;
	typedef SNode<ElmDataType> NodeType;
public:
	CCircleList(void);
	~CCircleList(void);
	ListNode GetHead() const
	{
		return m_pHead;
	}
	ListNode GetTail() const
	{
		return m_pTail;
	}
	ListNode GetMidNode() const
	{
		UINT n = GetLength() / 2;
		ListNode TempNode = m_pHead;
		for(UINT i = 0; i < n; ++i)
		{
			TempNode = TempNode->pNext;
		}
		return TempNode->pNext;
	}
	UINT GetLength() const
	{
		return m_ListLen;
	}
	void PushBack(const ElmDataType &data);
	void PushFront(const ElmDataType &data);
	void Reverse();
	ListNode RemoveAt(ListNode pos);
	ListNode RemoveAt(UINT nCountBack);
	ListNode InsertAt(ListNode pos, const ElmDataType &data);
	ListNode ModifyAt(ListNode pos, const ElmDataType &data);

	ListNode Find(const ElmDataType &data) const;
	ListNode FindByIndex(UINT Index) const;
	void Erase();
	void PrintList() const;
	void MergeList(CCircleList<ElmDataType> &lst);
	bool IsEmpty() const
	{
		return m_ListLen == 0;
	}
	//ListNode GetNode(const ElmDataType &data) const;
	
private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_ListLen;
};

#endif //_CIRCLELIST_H