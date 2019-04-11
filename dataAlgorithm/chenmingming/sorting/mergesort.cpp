/**
 * @description: 归并排序，先不断二分至1个元素
 * @author: michael ming
 * @date: 2019/4/11 20:52
 * @modified by: 
 */
#include <unordered_map>
using namespace std;
void merge(int* arr, size_t left, size_t mid, size_t right)
{
    int len = right -left + 1;
    int *temp = new int [len];
    size_t index = 0, i = left, j = mid + 1;
    while(i <= mid && j <= right)
        temp[index++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while(i <= mid)
        temp[index++] = arr[i++];
    while(j <= right)
        temp[index++] = arr[j++];
    for(int k = 0; k < len; ++k)
        arr[left++] = temp[k];
    delete [] temp;
    temp = NULL;
}

void divide(int *arr, size_t left, size_t right)
{
    if(left >= right)
        return;
    size_t mid = (left + right)/2;
    divide(arr, left, mid);
    divide(arr, mid+1, right);
    merge(arr, left, mid, right);
}
void mergesort(int* arr, size_t n)
{
    if(n < 2)
        return;
    size_t left = 0, right = n-1;
    divide(arr, left, right);
}