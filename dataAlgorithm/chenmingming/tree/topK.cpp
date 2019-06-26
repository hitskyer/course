/**
 * @description: 用堆求最大的k个元素
 * @author: michael ming
 * @date: 2019/5/30 0:06
 * @modified by: 
 */
#include "heap.cpp"
int main()
{
    int i = 0;
    const int len = 10;
    int data[len] = {2, 8, 1, 7, 12, 24, 6, 10, 90, 100};
    MinHeap intheap(5);//求前5大元素
    while(!intheap.full())
    {
        if(i < len)
            intheap.insert(data[i++]);
    }
    while(i < len)
    {
        if(data[i] > intheap.getMin())
        {
            intheap.delMin();
            intheap.insert(data[i]);
        }
        i++;
    }
    intheap.sort();
    intheap.print();
    return 0;
}