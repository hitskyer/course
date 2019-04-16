/**
 * @description: 循环有序数组，查找给定值
 * @author: michael ming
 * @date: 2019/4/17 0:25
 * @modified by: 
 */
#include <iostream>
#include "binarySearch_simple.cpp"
#define N 10
int circular_Arr_BS(int *arr, size_t low, size_t high, int num)
{
    size_t mid = low+(high-low)/2;
    if(arr[low] < arr[mid])
    {
        if(arr[mid] > num)
            return binarySearch_simple(arr,mid-low,num);
        else
            return circular_Arr_BS(arr,mid+1,high,num);
    }
    else
    {
        if(arr[mid] < num)
            return binarySearch_simple(arr,high-mid,num);
        else
            return circular_Arr_BS(arr,low,mid-1,num);
    }
}
int main()
{
    int arr[N] = {4,5,6,7,8,9,10,1,2,3};
    size_t mid = (N-1)/2;
    int num;
    cin >> num;
    if(arr[mid] == num)
        std::cout << mid;
    else
        std::cout << circular_Arr_BS(arr,0,N-1,num);
    return 0;
}
