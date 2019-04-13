/**
 * @description: 计数排序，找出数列中最大最小的数，并记录下每一个元素的个数，然后放回
 * @author: michael ming
 * @date: 2019/4/12 23:42
 * @modified by: 
 */
#include <unordered_map>
void countsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    int index = 0, min = arr[0], max = arr[0];
    for(int i = 1; i < n; ++i)
    {
        min = (arr[i] < min)? arr[i]:min;
        max = (arr[i] > max)? arr[i]:max;
    }
    int len = max-min+1;
    int *temp = new int [len]();
    for(int i = 0; i < n; ++i)
        temp[arr[i]-min]++;
    for(int i = min; i <= max; ++i)
    {
        for(int j = 0; j < temp[i-min]; ++j)
            arr[index++] = i;
    }
    delete[]temp;
    temp = NULL;
}
