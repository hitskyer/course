/**
 * @description: 数据有序(小到大)且无重复，查找给定值
 * @author: michael ming
 * @date: 2019/4/16 18:54
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
            return mid;
        else if(arr[mid] < num)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}
//int main()
//{
//    cout << "数组打印如下：" << endl;
//    int arr[N] = {1,2,3,4,5,6,7,8,9,10};
//    for(int i = 0; i < N; ++i)
//        cout << arr[i] << " ";
//    cout << "请输入要查找的数，将返回下标，不存在返回-1：";
//    int num;
//    cin >> num;
//    cout << num << " 的下标是：" << binarySearch_simple(arr,N,num) << endl;
//}