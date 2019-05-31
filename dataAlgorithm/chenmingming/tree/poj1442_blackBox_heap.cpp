/**
 * @description: 用大小堆求解
 * @author: michael ming
 * @date: 2019/5/31 23:21
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int num;
    vector<int> maxheap, minheap;
    while(cin >> num)
    {
        if(maxheap.empty())
        {
            maxheap.push_back(num);
            continue;
        }
        //----选择插入哪个堆-----
        if(!maxheap.empty() && num <= maxheap[0])
        {
            maxheap.push_back(num);
            push_heap(maxheap.begin(),maxheap.end());//默认采用 < , 大堆
        }
        else if(!maxheap.empty() && num > maxheap[0])
        {
            minheap.push_back(num);
            push_heap(minheap.begin(),minheap.end(),greater<int>());//小堆，采用 >
        }
        //----平衡两个堆的节点比列----
        if(maxheap.size() > minheap.size() && maxheap.size() - minheap.size() > 1)
        {
            minheap.push_back(maxheap[0]);//大堆顶进入小堆
            push_heap(minheap.begin(),minheap.end(),greater<int>());
            pop_heap(maxheap.begin(),maxheap.end());//堆顶到末尾了
            maxheap.pop_back();//删除到末尾的"堆顶"
        }
        else if(maxheap.size() < minheap.size())
        {
            maxheap.push_back(minheap[0]);
            push_heap(maxheap.begin(),maxheap.end());//默认采用 < , 大堆
            pop_heap(minheap.begin(),minheap.end(),greater<int>());
            minheap.pop_back();
        }
}