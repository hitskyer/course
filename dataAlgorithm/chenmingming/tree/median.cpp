/**
 * @description: 利用大小两个堆求中位数
 * @author: michael ming
 * @date: 2019/5/30 20:37
 * @modified by: 
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    const int len = 7;
    int staticArr[len] = {7,-1,9,0,8,77,24};//-1,0,7,*8*,9,24,77
    vector<int> maxheap, minheap;
    for(int i = 0; i < len; ++i)
    {
        if(maxheap.empty())
        {
            maxheap.push_back(staticArr[i]);
            continue;
        }
        //----选择插入哪个堆-----
        if(!maxheap.empty() && staticArr[i] <= maxheap[0])
        {
            maxheap.push_back(staticArr[i]);
            push_heap(maxheap.begin(),maxheap.end());//默认采用 < , 大堆
        }
        else if(!maxheap.empty() && staticArr[i] > maxheap[0])
        {
            minheap.push_back(staticArr[i]);
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
    if(maxheap.size())
        cout << "中位数为：" << maxheap[0] << endl;
    return 0;
}