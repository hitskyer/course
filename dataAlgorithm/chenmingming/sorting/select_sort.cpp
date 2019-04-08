/**
 * @description: 选择排序
 * @author: michael ming
 * @date: 2019/4/8 23:29
 * @modified by: 
 */
#include <unordered_map>
using namespace std;
void selectsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    size_t minIndex = 0;
    for (int i = 0; i < n-1; ++i)
    {
        minIndex = i;
        for(int j = i+1; j < n; ++j)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}
