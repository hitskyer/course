/**
 * @description: 冒泡排序
 * @author: michael ming
 * @date: 2019/4/8 20:19
 * @modified by: 
 */
#include <unordered_map>
using namespace std;
void bubblesort(int *arr, size_t n)
{
    if(n < 2)
        return;
    bool arrisok = false;
    for(size_t i = 0; i < n; ++i)
    {
        arrisok = true;
        for(size_t j = 1; j < n-i; ++j)
        {
            if(arr[j-1] > arr[j])
            {
                swap(arr[j-1],arr[j]);
                arrisok = false;
            }
        }
        if(arrisok)
            return;
    }
}

void bubblesort_2d(int *arr, size_t n)  //双向冒泡
{
    if(n < 2)
        return;
    bool arrisok = false;
    int left = 0, right = n-1;
    while(left < right)
    {
        arrisok = true;
        for(size_t i = left; i < right; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
                arrisok = false;
            }
        }
        right--;
        for(size_t i = right; i > left; --i)
        {
            if(arr[i] < arr[i-1])
            {
                swap(arr[i],arr[i-1]);
                arrisok = false;
            }
        }
        left++;
        if(arrisok)
            return;
    }
}