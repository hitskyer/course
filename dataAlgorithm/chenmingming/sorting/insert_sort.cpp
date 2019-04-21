/**
 * @description: 插入排序
 * @author: michael ming
 * @date: 2019/4/8 21:43
 * @modified by: 
 */
#include <unordered_map>
using namespace std;
void insertsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    for (int i = 0; i < n; ++i)
    {
        for(int j = i; j > 0 && arr[j-1] > arr[j]; --j)
        {
            swap(arr[j-1],arr[j]);
        }
    }
}
void insertsort_opt1(int *arr, size_t n)
{
    if(n < 2)
        return;
    int temp;
    for (int i = 1; i < n; ++i)
    {
        temp = arr[i];
        int j = i-1;
        for(; j >= 0 && arr[j] > temp; --j)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1] = temp;
    }
}