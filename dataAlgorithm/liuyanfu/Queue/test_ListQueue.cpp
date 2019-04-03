#include <iostream>
#include "ListQueue.cpp"

using namespace std;


int main()
{
	ListQueue<int> ique;
	for(int i = 0; i < 10; ++i)
	{
		if(i == 0 || i ==  3 || i == 6 || i == 9)
			ique.dequeue();
		if(ique.empty())
			cout << "Current queue is Empty!" << endl;
		ique.enqueue(i * 2 + i);
		cout << "Current queue length is " << ique.getlength() << endl;
		ique.print();
		cout << endl;
	}
	return 0;
}