/**
 * @description: 堆
 * @author: michael ming
 * @date: 2019/5/26 22:22
 * @modified by: 
 */
#include <iostream>
#include <limits.h>
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
    int heapsize()
    {
        return heap_size;
    }
    void MinHeapify(int i)
    {
        int l = left(i), r = right(i);
        int min = i;
        if(l < heap_size && arr[l] < arr[i])
            min = l;
        if(r < heap_size && arr[r] < arr[min])
            min = r;
        if(min != i)
        {
            swap(arr[i], arr[min]);
            MinHeapify(min);
        }
    }
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
    int getMin()
    {
        return arr[0];
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
//int main()
//{
//    MinHeap minheap(8);
//    minheap.insert(6);
//    minheap.insert(8);
//    minheap.insert(12);
//    minheap.insert(4);
//    minheap.insert(15);
//    minheap.insert(0);
//    minheap.insert(5);
//    minheap.insert(9);
//    minheap.insert(10);
//    minheap.delMin();
//    cout << minheap.getMin() << endl;
//    return 0;
//}