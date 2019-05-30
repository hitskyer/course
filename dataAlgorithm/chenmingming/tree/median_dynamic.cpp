/**
 * @description: 中位数求解，利用大小堆，动态数据插入
 * @author: michael ming
 * @date: 2019/5/30 23:13
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
    int num;
    vector<int> maxheap, minheap, allnum;
    while(cin >> num)
    {
        allnum.push_back(num);
        if(maxheap.empty())
        {
            maxheap.push_back(num);
            cout << "排序后的数组：" << endl;
            printVec(allnum);
            cout << "中位数为：" << maxheap[0] << endl;
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
        sort(allnum.begin(),allnum.end());
        cout << "排序后的数组：" << endl;
        printVec(allnum);
        if(maxheap.size())
            cout << "中位数为：" << maxheap[0] << endl;
    }
    return 0;
}