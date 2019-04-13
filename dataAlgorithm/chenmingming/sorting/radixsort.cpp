/**
 * @description: 基数排序
 * @author: michael ming
 * @date: 2019/4/13 12:43
 * @modified by: 
 */
#include <unordered_map>
void radix_countsort(int *arr, size_t n, int exp)
{
    int numOfEachBucket[10] = {0};
    for(int i = 0; i < n; ++i)
        ++numOfEachBucket[(arr[i]/exp)%10];
    for(int i = 1; i < 10; ++i)
        numOfEachBucket[i] += numOfEachBucket[i-1];
    int *temp = new int [n];
    for(int i = n-1; i >= 0; --i)
        temp[--numOfEachBucket[(arr[i]/exp)%10]] = arr[i];
    for(int i = 0; i < n; ++i)
        arr[i] = temp[i];
    delete[]temp;
    temp = NULL;
}
void radixsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    int maxVal = arr[0];
    for(size_t i = 0; i < n; ++i)
        maxVal = arr[i] > maxVal ? arr[i] : maxVal;
    for(int exp = 1; maxVal/exp > 0; exp *= 10)
        radix_countsort(arr, n, exp);
}