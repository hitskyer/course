/**
 * @description: 查找最后一个值等于给定值的元素
 * @author: michael ming
 * @date: 2019/4/16 20:24
 * @modified by: 
 */
#include <iostream>
#define N 10
using namespace std;
int binarySearch_simple(int *arr,size_t n,int num)
{
    size_t low = 0, high = n-1;
    while(low <= high)
    {
        size_t mid = low+(high-low)/2;
        if(arr[mid]==num)
        {
            if(mid == n-1 || arr[mid+1] != num)   //最后一个元素了，或者后面的不等于num
                return mid;
            else    //否则最后一个元素还在后面
                low = mid+1;
        }
        else if(arr[mid] < num)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}
int main()
{
    cout << "数组打印如下：" << endl;
    int arr[N] = {1,1,2,2,4,5,6,8,8,9};
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "请输入要查找的数，将返回最后一个符合的下标，不存在返回-1：";
    int num;
    cin >> num;
    cout << num << " 的下标是：" << binarySearch_simple(arr,N,num) << endl;
}