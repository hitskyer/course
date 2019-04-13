/**
 * @description: 堆排序，建堆（升序建大堆，降序建小堆）,交换堆顶与最后一位无序数据,调整堆，递归，交换调整
 * @author: michael ming
 * @date: 2019/4/12 23:05
 * @modified by: 
 */
#include <unordered_map>
void adjust(int *arr, size_t i, size_t n)
{
    size_t lowerLeftNode = i*2+1;
    while(lowerLeftNode < n)
    {
        if(lowerLeftNode + 1 < n && arr[lowerLeftNode] < arr[lowerLeftNode+1])
            ++lowerLeftNode;
        if(arr[i] > arr[lowerLeftNode])
            break;
        swap(arr[i], arr[lowerLeftNode]);
        i = lowerLeftNode;
        lowerLeftNode = i*2+1;
    }
}
void makeheap(int *arr, size_t n)
{
    for(size_t i = n/2-1; i >= 0; i--)
    {
        adjust(arr, i, n);
        if(i ==0)
            break;
    }
}
void heapsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    makeheap(arr,n);
    for(size_t i = n-1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        adjust(arr,0,i);
        if(i == 0)
            break;
    }
}