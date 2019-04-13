#ifndef _TEST_H
#define _TEST_H
#include <iostream>
#define NUM_SIZE 500

using namespace std;

class SortClass
{
private:
	int arr[NUM_SIZE];
	int temparr[NUM_SIZE];
public:
	SortClass(void);
	~SortClass(void);

	void RandNum();
	void Bobble();
	void InsertArr();
	void Select();
	void Print();
	void PrintSort();
	void InitTempArr();
private:
	inline void swap(int &a, int &b);
};

#endif
