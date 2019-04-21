/**
 * @description: 希尔排序，分间隔插入排序，间隔不断缩小至1
 * @author: michael ming
 * @date: 2019/4/11 20:18
 * @modified by: 
 */
#include <unordered_map>
using namespace std;
void shellsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    for (size_t gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; ++i)
        {
            for(size_t j = i; int(j-gap) >=0 && arr[j-gap] > arr[j]; j -= gap)
                swap(arr[j-gap],arr[j]);
        }
    }
}
void shellsort_opt1(int *arr, size_t n)
{
    if(n < 2)
        return;
    int temp;
    for (size_t gap = n/2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; ++i)
        {
            temp = arr[i];
            int j = i - gap;
            for(; int(j) >=0 && arr[j] > temp; j -= gap)
                arr[j+gap] = arr[j];
            arr[j+gap] = temp;
        }
    }
}