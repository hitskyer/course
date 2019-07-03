/**
 * @description: 分治法求逆序数（归并排序法）
 * @author: michael ming
 * @date: 2019/7/3 23:27
 * @modified by: 
 */
#include <iostream>
class ReverseOrderCount
{
    int sum;
    void divide(int *a, int left, int right)
    {
        if(left >= right)
            return;
        int mid = (left+right)/2;
        divide(a,left,mid);
        divide(a,mid+1,right);
        merge(a,left,mid,right);
    }
    void merge(int *a, int left, int mid, int right)
    {
        int i = left, j = mid+1, len = right-left+1, idx = 0;
        int *temp = new int [len];
        while(i <= mid && j <= right)
        {
            if(a[i] <= a[j])
                temp[idx++] = a[i++];
            else
            {
                sum += mid-i+1;//左边i后面的都比a[j]大
                temp[idx++] = a[j++];
            }
        }
        while(i <= mid)//剩余的半边
            temp[idx++] = a[i++];
        while(j <= right)//剩余的半边
            temp[idx++] = a[j++];
        for(idx = 0; idx < len; ++idx)
        {
            a[left++]= temp[idx];  //把有序的临时数组写入原来数组的起始位置
        }
        delete [] temp;  //释放空间
        temp = NULL;  //指针置空
    }
public:
    int count(int *a, int n)
    {
        sum = 0;
        divide(a,0,n-1);
        return sum;
    }
};

int main()
{
    ReverseOrderCount roc;
    int arr[6] = {2,4,3,1,5,6};
    std::cout << "arr数组的逆序数是：" << roc.count(arr,6);
    return 0;
}