/**
 * @description: 快速排序，找一个哨兵，左边都是小于的，右边都是大于的，递归
 * @author: michael ming
 * @date: 2019/4/11 21:41
 * @modified by: 
 */
#include <unordered_map>
using namespace std;
void selectMiddle(int *arr, size_t left, size_t right)
{
    size_t mid = left + (right-left)/2;
    if(arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    if(arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if(arr[mid], arr[left])
        swap(arr[mid], arr[left]);
}
void partition(int* arr, size_t left, size_t right, size_t &PL_index, size_t &PR_index)
{
    selectMiddle(arr,left,right);
    int Pval = arr[left];
    size_t i = left, j = right;
    while(i < j)    //等于哨兵的数都在一边
    {
        while(i < j && Pval <= arr[j])  //都在右边
            j--;
        swap(arr[i], arr[j]);
        while(i < j && Pval > arr[i])
            i++;
        swap(arr[i], arr[j]);
    }
    size_t Pindex = i;
    size_t leftPnum = 0, rightPnum = 0;
    PL_index = PR_index = i;
    for(i = Pindex+1; i <= right; ++i)  //右边哨兵往中间靠
    {
        if(arr[i] == Pval)
        {
            ++rightPnum;
            PR_index = Pindex + rightPnum;
            swap(arr[i], arr[PL_index]);
        }
    }
}

void quick_sort(int *arr, size_t left, size_t right)
{
    if(left >= right)
        return;
    else if(right - left >= 1 && right - left <= 20)
        shellsort(&arr[left], right - left +1);
    else
    {
        size_t PL_index, PR_index;
        partition(arr, left, right, PL_index, PR_index);
        if(PR_index == right && PL_index != left)
            quick_sort(arr,left,PL_index-1);
        else if(PL_index = left && PR_index != right)
            quick_sort(arr,PR_index+1,right);
        else if(PL_index == right && PR_index == right)
            return;
        else
        {
            quick_sort(arr,left,PL_index-1);
            quick_sort(arr,PR_index+1,right);
        }
    }
}
void quicksort(int* arr, size_t n)
{
    if(n < 2)
        return;
    size_t left = 0, right = n-1;
    quick_sort(arr, left, right);
}
