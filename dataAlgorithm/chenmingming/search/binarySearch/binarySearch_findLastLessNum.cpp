/**
 * @description: 查找最后一个小于等于给定值的元素
 * @author: michael ming
 * @date: 2019/4/16 23:09
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
        if(arr[mid] > num)
            high = mid-1;
        else if(arr[mid] <= num)
        {
            if(mid == n-1 || arr[mid+1] > num)  //最后一个元素，或者后面的比它大了
                return mid; //它是最后一个小于等于的
            else
                low = mid+1;    //否则后面还有满足的，下限往上加
        }
    }
    return -1;
}
//int main()
//{
//    cout << "数组打印如下：" << endl;
//    int arr[N] = {1,2,2,4,5,6,7,10,10,10};
//    for(int i = 0; i < N; ++i)
//        cout << arr[i] << " ";
//    cout << "请输入一个数，返回最后一个小于等于给定值的元素的下标，不存在返回-1：";
//    int num;
//    cin >> num;
//    cout << num << " 的下标是：" << binarySearch_simple(arr,N,num) << endl;
//}