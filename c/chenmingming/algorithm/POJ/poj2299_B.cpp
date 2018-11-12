#include<iostream>
#include<cstring>
using namespace std;
long long int sum=0;
void merge(long long *arr,size_t left,size_t mid,size_t right)
{
    int len = right - left + 1;
    long long int *temp = new long long int [len];  //数组较长时请用new，不然栈空间容易溢出
    size_t index = 0;
    size_t i = left, j = mid + 1;
    while(i <= mid && j <= right)
    {
        if(arr[i]<=arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
            sum += mid - i + 1; //左边数比右边大，那么左边剩余的也比其大！！！
        }
        //对两边的数组从小到大放入临时空间
    }
    while(i <= mid)     //比较完后，左半边有没放进去的，直接写入
    {
        temp[index++]= arr[i++];
    }
    while(j <= right)   //比较完后，右半边有没有放进去的，直接写入
    {
        temp[index++]= arr[j++];
    }
    for(int k = 0;k< len;++k)
    {
        arr[left++ ]= temp[k];  //把有序的临时数组写入原来数组的起始位置
    }
    delete [] temp;  //释放空间
    temp = NULL;  //指针置空
}
void divide(long long *arr,size_t left,size_t right)
{
    if(left == right)
    {
        return;
    }
    size_t mid = (left+right)/2;  //找出区间中部的数，将数组分段
    divide(arr,left,mid);  //递归调用，对左边继续分段；
    divide(arr,mid+1,right);  //递归调用，对右边继续分段；
    merge(arr,left,mid,right); //对左右两半进行排序合并成一小段有序的数组
}
void mergesort(size_t dsize, long long *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    divide(arr,left,right);
}

int main()
{
    const long int N = 500000;
    long int len,len1;
    long long int *arr = new long long int [N];
    long long int j=0,temp;
    memset(arr,0,sizeof(long long)*N);
    while(cin >> len && len != 0)
    {
        len1=len;
        j=0;
        while(len1--)   //先输入数组
        {
            cin >> temp;
            arr[j++] = temp;
        }
        mergesort(len,arr);
        printf("%I64d\n",sum);
        sum = 0;
    }
    delete [] arr;
    arr = NULL;
    return 0;
}