/**
 * @description: 查找第一个大于等于给定值的元素
 * @author: michael ming
 * @date: 2019/4/16 20:54
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
        if(arr[mid] >= num) //当找到要求的值时
        {
            if(mid == 0 || arr[mid-1] < num)    //判断是第一个元素，或者前面的比我小
                return mid; //当前满足
            else    //否则满足要求的还在前面
                high = mid-1;
        }
        else if(arr[mid] < num)
            low = mid+1;
    }
    return -1;
}
int main()
{
    cout << "数组打印如下：" << endl;
    int arr[N] = {1,2,2,4,5,6,7,8,9,10};
    for(int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "请输入一个数，将返回第一个大于等于它的下标，不存在返回-1：";
    int num;
    cin >> num;
    cout << num << " 的下标是：" << binarySearch_simple(arr,N,num) << endl;
}