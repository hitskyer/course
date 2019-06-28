#include <iostream>
//#include "HashTableList.h"
#include "HashTableList.cpp"
using namespace std;

int main()
{
	HashTableList htl_1;
	int result = 0;
	result = htl_1.hashFunc_1(4321);
	cout << result << endl;
	cout << 1234*1234 << endl;

	cout << htl_1.hashFunc_2(345, 45) << endl;
	cout << htl_1.hashFunc_3(3749) << endl;


	HashTableList htl(19);		//moudle = 19
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,28,29,41,45,46,43,48};
	int len = sizeof(arr)/sizeof(int);
	for (int i = 0; i < len; ++i)
	{
		htl.Insert(arr[i]);
	}
	
	htl.print();

	bool flag = false;
	flag = htl.Contain(52);
	cout << flag <<endl;

	flag = htl.Contain(45);
	cout << flag <<endl;

	cout << htl.Count() << endl;

	flag = htl.Delete(14);
	flag = htl.Delete(11);
	flag = htl.Delete(16);
	cout << flag << endl;

	flag = htl.Delete(44);
	cout << flag << endl;

	htl.print();

	//system("pause");
	return 0;
}
