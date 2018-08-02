#include "List.h"

int main()
{
	M::list list;

	//插入10个元素
	for (int i = 0; i < 10; i++)
	{
		list.insert(0, i);
	}
	cout << list;

	//在头部插入元素
	list.insert(0, 111);
	cout << list;

	//在尾部插入元素
	list.insert(list.getlength(), 111);
	cout << list;

	//在头部删除元素
	list.erase(0);
	cout << list;

	//在尾部删除元素
	list.erase(list.getlength()-1);
	cout << list;

	//在中间删除元素
	list.erase(1);
	cout << list;

	return 0;
}