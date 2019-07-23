#include <iostream>
#include "Heap.h"
#include "FindMedian.h"
#include "FindTopK.h"
using namespace std;


int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(3);
	vec.push_back(21);
	vec.push_back(11);
	vec.push_back(8);
	vec.push_back(34);
	vec.push_back(55);
	vec.push_back(23);
	vec.push_back(38);
	vec.push_back(19);
	Heap<int, vector<int>, Greater<int>> hp;
	hp.make_heap(vec.begin(), vec.end());
	cout << hp.heap_top() << endl;
	hp.print();
	hp.heap_push(66);
	hp.print();
	cout << hp.heap_pop() << endl;
	hp.print();
	cout << hp.heap_top() << endl;
	while(!hp.empty())
	{
		cout << hp.heap_pop() << endl;
	}

	FindMedian fmid;
	fmid.addNum(12);
	fmid.addNum(2);
	fmid.addNum(32);
	fmid.addNum(33);
	fmid.addNum(22);
	fmid.addNum(19);
	fmid.addNum(10);
	fmid.addNum(46);
	fmid.addNum(51);
	fmid.addNum(39);
	cout << fmid.findMedian() << endl;

	FindTopK ftop;
	ftop.findTopK(vec, 3).print();
	return 0;
}