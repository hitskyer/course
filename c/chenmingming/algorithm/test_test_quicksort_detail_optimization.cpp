#include<iostream>
using namespace std;
size_t parr [2];
int cyctimes=0;
void shellsort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t gap = 1;
    size_t j=0;
    for(gap=dsize/2;gap> 0;gap /= 2)
    {
        for(size_t i = gap;i < dsize;++i)
        {
            for(j=i;int(j-gap)>=0 && arr[j-gap]> arr[j];j -= gap)
            //int()转换类型，避免溢出，相当于分组的插入排序
            {
                swap(arr[j-gap],arr[j]);
            }
        }
    }
}
void selectmedianofthree1(int *arr, size_t left, size_t right)
{
    size_t mid = left + (right - left)/2;
    if(arr[mid]>arr[right])
    {
        swap(arr[mid],arr[right]);
    }
    if(arr[left]>arr[right])
    {
        swap(arr[left],arr[right]);
    }
    if(arr[mid]>arr[left])
    {
        swap(arr[mid],arr[left]);
    }
}
void partion1_opti2(int *arr, size_t left, size_t right, size_t &pl_index, size_t &pr_index)//数据分段
{
    selectmedianofthree1(arr,left,right);  //找出中间大小的哨兵，让分段尽量均匀，提高效率
    int pval = arr[left];  //中间大小的数赋值给哨兵
    int i = left, j = right;
    while(i < j)
    {
        while(i < j && pval <= arr[j])
            --j;
        swap(arr[i],arr[j]);
        while(i < j && pval >= arr[i])
            ++i;
        swap(arr[i],arr[j]);
    }
    size_t pindex = i;
    size_t leftpnum = 0, rightpnum = 0;
    pl_index = pindex - leftpnum;
    pr_index = pindex + rightpnum;
    // for(i = pindex-1; i >= left; --i)
    // {
    //     if(arr[i] == pval)
    //     {
    //         ++leftpnum;
    //         pl_index = pindex - leftpnum;
    //         swap(arr[i],arr[pl_index]);   
    //     }
    // }
    // for(i = pindex+1; i <= right; ++i)
    // {
    //     if(arr[i] == pval)
    //     {
    //         ++rightpnum;
    //         pr_index = pindex + rightpnum;
    //         swap(arr[i],arr[pr_index]);  
    //     }
    // }
}
void qsort1_opti2(int *arr, size_t left, size_t right, int deep)
{
    if(left >= right)
    {
        return;
    }
    else if(right-left == 1)
    //只有两个数直接比较交换（也可以设置长度小于X（比如10），调用其他排序，如归并，减少不必要的调用快排）
    {
        if(arr[left]>arr[right])
        {
            swap(arr[left], arr[right]);
        }
    }
    // else if(right-left > 1 && right-left < 20)  //数组长度较小时，调用希尔排序，减少调用快排
    // {
    //     size_t len = right - left + 1;
    //     shellsort(len, &arr[left]); //数组首地址为&arr[left]
    // }
    else
    {
        size_t pl_index;  //首位哨兵的下标
        size_t pr_index;  //末位哨兵的下标
        partion1_opti2(arr,left,right,pl_index,pr_index);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        if(pr_index == right && pl_index != left)  //哨兵群位于数组最右边，且左边还有数据
        {
            qsort1_opti2(arr,left,pl_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(pl_index == left && pr_index != right)  //哨兵群位于数组最左边，且右边还有数据
        {
            qsort1_opti2(arr,pr_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else if(pl_index == left && pr_index == right) //全部是哨兵，两侧无数据，退出
        {
            return;
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort1_opti2(arr,left,pl_index-1,deep);
            qsort1_opti2(arr,pr_index+1,right,deep);
        }
    }
}
void quicksort1_opti2(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort1_opti2(arr,left,right,deep);
}

void sort(int *arr)
{
    size_t dsize = 11;
    for(int i=0;i <= 10;++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;



    size_t left = 0, right = dsize-1;
    quicksort1_opti2(dsize,arr);


    for(int i=0;i <= 10;++i)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;

}
int main()
{
    int arr1[]={6,5,7,1,3,6,6,8,4,2,0};
    int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
    int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
    int arr4[]={2,1,1,1,1,1,1,1,1,1,1};
    int arr5[]={1,1,1,1,1,1,1,1,1,1,1};
	int *p = arr1;
    sort(p);
    sort(arr2);
    sort(arr3);
    sort(arr4);
    sort(arr5);
    return 0;
}
