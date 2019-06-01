/**
 * @description: 用大小堆求解
 * @author: michael ming
 * @date: 2019/5/31 23:21
 * @modified by: 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int arr[30005], total[30005];
int main()
{
    int arrlen, k, arrindex=1, maxheapsize=0, insertnum , minheapsize;
    cin >> arrlen >> k;
    for(int i = 1; i <= arrlen; ++i)
        cin >> arr[i];
    for(int i = 1; i <= k; ++i)
        cin >> total[i];
    vector<int> maxheap, minheap;
    for(int i = 1; i <= k; ++i)
    {
        maxheapsize++;
        minheapsize = total[i] - maxheapsize;
        insertnum = total[i] - total[i-1];
        if(insertnum == 0 && !minheap.empty())
        {
            maxheap.push_back(minheap[0]);
            push_heap(maxheap.begin(), maxheap.end());//默认采用 < , 大堆
            pop_heap(minheap.begin(), minheap.end(), greater<int>());
            minheap.pop_back();
        }
        while(insertnum--)
        {
            if (maxheap.empty())
            {
                maxheap.push_back(arr[arrindex]);
            }
            else
            {
                //----选择插入哪个堆-----
                if (arr[arrindex] <= maxheap[0])
                {
                    if(maxheap.size() >= maxheapsize)
                    {
                        minheap.push_back(maxheap[0]);//大堆顶进入小堆
                        push_heap(minheap.begin(), minheap.end(), greater<int>());
                        pop_heap(maxheap.begin(), maxheap.end());//堆顶到末尾了
                        maxheap.pop_back();//删除到末尾的"堆顶"
                    }
                    maxheap.push_back(arr[arrindex]);
                    push_heap(maxheap.begin(), maxheap.end());//默认采用 < , 大堆

                }
                else if (arr[arrindex] > maxheap[0])
                {
                    if(minheap.size() >= minheapsize)
                    {
                        maxheap.push_back(minheap[0]);
                        push_heap(maxheap.begin(), maxheap.end());//默认采用 < , 大堆
                        pop_heap(minheap.begin(), minheap.end(), greater<int>());
                        minheap.pop_back();
                    }
                    minheap.push_back(arr[arrindex]);
                    push_heap(minheap.begin(), minheap.end(), greater<int>());//小堆，采用 >
                }
            }
            arrindex++;
        }
        cout << maxheap[0] << endl;
    }
    return 0;
}