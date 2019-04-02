#include <iostream>
#include "CircleQueue.cpp"

using namespace std;

int main()
{
	CircleQueue<int> iaque;

	if(!iaque.dequeue())
		cout << "dequeue failed!" << endl;
	iaque.enqueue(20);
	cout << "after enqueue 20 current queue length is " << iaque.getlength() << endl;
	iaque.erase();
	if(iaque.empty())
		cout << "current queue has been cleared!" << endl;
	iaque.enqueue(20 + 1);
	iaque.enqueue(20 + 2);
	iaque.enqueue(20 + 3);
	iaque.enqueue(20 + 4);
	iaque.enqueue(20 + 5);		
	if(!iaque.enqueue(20 + 6))
		cout << "enqueue failed ,becasue of current queue is full!" <<endl;

	iaque.dequeue();
	iaque.dequeue();
	cout << "after dequeue 2 element ,current queue length is " << iaque.getlength() << endl;
	iaque.enqueue(26);
	iaque.print();

	return 0;
}