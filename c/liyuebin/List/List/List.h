
#ifndef LIST_H
#define  LIST_H

#include <iostream>
using namespace std;

namespace M
{
	//list 类
	class list
	{
	public:
		//基本节点的组成
		typedef struct Node
		{
			int item;    //数据域
			Node* next;  //指针域
		}Node, *PNode;
	private:
		//头节点
		PNode Header = nullptr;

		//当前链表长度
		int length = 0;

		//获取目标位置的前一个节点
		PNode getprenode(int Index);
	public:
		list();
		~list();

		//插入元素
		bool insert(int Index, int Elem);

		//删除元素
		bool erase(int Index);

		//获取长度
		int getlength(){ return length; };

		//销毁链表
		void destory();

		//重载输出运算符
		friend ostream &operator<<(ostream &o, list & l);
	};

}
#endif

