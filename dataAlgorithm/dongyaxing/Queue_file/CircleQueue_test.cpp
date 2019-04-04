#include<iostream>
#include "CircleQueue.h"
#include "CircleQueue.cpp"

using namespace std;

int main()
{
	CircleQueue<int> cq;
	if(!cq.DeQueue())
		std::cout << "Empty Queue" << std::endl;
	std::cout << std::endl;

	std::cout << "push a num £º"<< std::endl;
	cq.EnQueue(20);
	std::cout << "queue length is £º" << cq.GetLength() << std::endl << std::endl;

	std::cout << "pop a num £º"<< std::endl;
	cq.DeQueue();
	if(cq.Empty())
		std::cout << "queue length is £º" << cq.GetLength() << std::endl << std::endl;


	for(int i = 0; i < 10; ++i)
	{
		cq.EnQueue(i + 11);
	}
	cq.Print();
	std::cout << "queue length is £º" << cq.GetLength() << std::endl;

	if(!cq.EnQueue(22))
		std::cout << "queue full£¡" << std::endl;
	std::cout << std::endl;

	std::cout << "pop 5 nums £º"<< std::endl;
	cq.DeQueue();
	cq.DeQueue();
	cq.DeQueue();
	cq.DeQueue();
	cq.DeQueue();
	for(int i = 0; i < 10; ++i)
	{
		cq.EnQueue(i + 11);
		if(!cq.EnQueue(22))
		{
			std::cout << "queue full£¡" << std::endl;
			break;
		}
	}
	cq.Print();
	std::cout << "queue length is £º" << cq.GetLength() << std::endl;
	
	system("pause");
	return 0;
}