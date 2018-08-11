
#include "List.h"

namespace M
{
	//初始化头节点
	list::list()
	{
		length = 0;
		Header = new Node{ 0, nullptr };
	}

	//销毁头节点
	list::~list()
	{
		destory();
	}
	// 获取目标位置的前一个节点
	list::PNode list::getprenode(int Index)
	{
		// -> 0 1 2 3 4 5 6 7 ↓

		// 获取头节点
		PNode node = Header;

		// 根据传入的值获取下一个节点
		for (int i = 0; i < Index; ++i)
			node = node->next;

		// 返回找到的节点
		return node;
	}
	//插入元素
	bool list::insert(int Index, int Elem)
	{
		//1.检查位置是否有效
		if (Index<0 || Index> length)
			return false;

		//2.获取前一个位置的节点
		PNode PreNode = getprenode(Index);

		//3.创建新的节点 并且修改指针
		PNode NewNode = new Node{ Elem, PreNode->next };
		PreNode->next = NewNode; 

		//改变大小 返回true
		++length;
		return true;
	}

	//删除元素
	bool list::erase(int Index)
	{
		//1.检查位置是否有效
		if (Index<0 || Index> length-1)
			return false;

		//2.获取前一个位置的节点
		PNode PreNode = getprenode(Index);

		//3.删除指针
		PNode TemNode = PreNode->next;
		PreNode->next = PreNode->next->next;
		delete[] TemNode;

		//改变大小 返回true
		--length;
		return true;
	}
	//销毁链表
	void list::destory()
	{
		PNode node = Header;

		while (node)
		{
			PNode Temp = node->next;
			delete node;
			node = Temp;
		}
	}

	//重载输出运算符
	ostream &operator<<(ostream& o, list & l)
	{

		//获取头节点
		list::PNode node = l.Header->next;


		//当前节点不为nullptr时 输出数据域
		while (node)
		{
			o << node->item << " ";
			node = node->next;
		}
		cout << endl;
		return o;
	}
	
}