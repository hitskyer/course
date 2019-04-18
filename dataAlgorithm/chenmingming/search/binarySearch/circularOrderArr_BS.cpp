/**
 * @description: 循环有序数组，查找给定值
 * @author: michael ming
 * @date: 2019/4/17 0:25
 * @modified by: 
 */
#include <iostream>
#define N 10
int circular_Arr_BS(int *arr, size_t n, int num)
{
    size_t low = 0, high = n-1;
    while(low <= high)
    {
        size_t mid = low+(high-low)/2;
        if(arr[mid] == num)
            return mid;
        if(arr[mid] < arr[low]) //转折点在左边,右边有序
        {
            if(arr[mid] <= num && num <= arr[high]) //数据在右边
                low = mid+1;
            else
                high = mid-1;
        }
        else    //转折点在右边，左边有序
        {
            if(arr[low] <= num && num < arr[mid])   //数据在左边
                high = mid-1;
            else
                low = mid+1;
        }
    }
    return -1;
}
int main()
{
    int arr[N] = {4,5,6,7,8,9,10,1,2,3};
    size_t mid = (N-1)/2;
    int num;
    std::cin >> num;
    std::cout << circular_Arr_BS(arr,N,num);
    return 0;
}