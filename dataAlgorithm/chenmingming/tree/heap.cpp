/**
 * @description: 堆
 * @author: michael ming
 * @date: 2019/5/26 22:22
 * @modified by: 
 */
#include <iostream>
using namespace std;
class MinHeap
{
    int *arr;
    int capacity;
    int heap_size;
public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        arr = new int [capacity];
    }
    ~MinHeap()
    {
        delete [] arr;
    }
    void MinHeapify(int index)
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return 2*i+1;
    }
    int right(int i)
    {
        return 2*i+2;
    }
    void delMin()
    {
        if(heap_size <= 0)
            return;
        arr[0] = arr[heap_size-1];
        heap_size--;
        MinHeapify(0);
    }
    void modify(int i, int new_val)
    {
        arr[i] = new_val;
        while(i > 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    int getMin()
    {
        return arr[0];
    }
    void delAt(int i)
    {

    }
    void insert(int val)
    {
        if(heap_size == capacity)
        {
            cout << "overflow!" << endl;
            return;
        }
        heap_size++;
        int i = heap_size-1;
        arr[i] = val;
        while(i > 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
};