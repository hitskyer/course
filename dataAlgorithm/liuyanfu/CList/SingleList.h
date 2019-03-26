#ifndef _SINGLELIST_H
#define _SINGLELIST_H

template <typename ElmDataType>
struct SNode
{
	ElmDataType data;
	SNode<ElmDataType>* pNext;
};

typedef unsigned int UINT;


template <typename ElmDataType>
class SingleList
{
public:
	typedef SNode<ElmDataType>* ListNode;
	typedef SNode<ElmDataType> NodeType;
public:
 	SingleList(void);
 	~SingleList(void);

	bool IsEmpty() const
	{
		return m_nListLen == 0;
	}

	UINT GetSize() const
	{
		return m_nListLen;
	}

	ListNode GetHeadNode() const
	{
		return m_pHead;
	}

	ListNode GetTailNode() const
	{
		return m_pTail;
	}

	void AddHead(const ElmDataType &data);
	void AddTail(const ElmDataType &data);

	ListNode InsertAt(ListNode pos, const ElmDataType &data);
	ListNode RemoveAt(ListNode pos);
	ListNode ModifyAt(ListNode pos, const ElmDataType &data);
	ListNode Find(const ElmDataType &data);
	void Erase();

	ListNode GetNode(const ElmDataType &data) const;

	void PrintList() const;
	void ReverseList();

	ListNode RemoveAt(UINT nCountBack);//删除倒数第n个节点
	ListNode GetMidNode();//获得当前链表的中间节点
private:
	ListNode m_pHead;
	ListNode m_pTail;
	UINT m_nListLen;
};


#endif