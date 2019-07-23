#include "Heap.cpp"

void print(int* arr, int n)
{
	for(int i = 1; i <= n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	Heap<int> hp(20);
	hp.Insert(23);
	hp.Insert(21);
	hp.Insert(32);
	hp.Insert(11);
	hp.Insert(5);
	hp.Insert(33);
	hp.Insert(2);
	hp.Insert(45);
	hp.Insert(36);
	hp.Insert(55);
	hp.print();
	hp.RemoveMax();
	hp.print();

	int arr[] = {0,23,21,32,11,5,33,2,45,36,55};
	hp.BuildMaxHeap(arr, sizeof(arr)/sizeof(arr[0])-1);
	print(arr, sizeof(arr)/sizeof(arr[0])-1);
	hp.HeapSort(arr, sizeof(arr)/sizeof(arr[0])-1);
	print(arr, sizeof(arr)/sizeof(arr[0])-1);
}