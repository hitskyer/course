#ifndef _CIRCLELISTNOHEAD_H
#define _CIRCLELISTNOHEAD_H

template<typename ElmDataType>
struct SNode
{
	ElmDataType data;
	SNode* pNext;
};

typedef unsigned int UINT;

template<typename ElmDataType>
class CircleListNH
{
public:
	typedef SNode<ElmDataType>* ListNode;
	typedef SNode<ElmDataType>  NodeType;

	CircleListNH(void);
	~CircleListNH(void);

	bool IsEmpty() const
	{
		return m_ListLen == 0;
	}

	UINT GetLength();
	ListNode GetHeadNode() const
	{
		return m_pHead;
	}
	ListNode GetTailNode() const
	{
		return m_pTail;
	}
	ListNode GetMidNode();
	ListNode GetNode(const int &data) const;

	void AddHead(const int &data);
	void AddTail(const int &data);

	ListNode InsertAt(ListNode pos, const int &data);
	ListNode ModifyAt(ListNode pos, const int &data);
	ListNode RemoveAt(ListNode pos);
	ListNode RemoveAt(UINT nCountBack);
	void Erase();

	ListNode Find(const int &data);
	void PrintList() const;
	void Reverse();

private:
	UINT m_ListLen;
	ListNode m_pHead;
	ListNode m_pTail;
};

#endif //_CIRCLELISTNOHEAD_H