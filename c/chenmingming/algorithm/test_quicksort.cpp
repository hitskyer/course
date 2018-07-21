#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include <string.h>
const size_t G_BigSize    = 1000000;
const size_t G_SmallSize  = 1000;
const int    G_CycleTimes = 1000;

/*
 * 4.希尔排序，分组插入排序，相隔gap个数的都为一组，从第gap个数开始
 */
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

/*
 时间复杂度分析
[参考](https://blog.csdn.net/ginnosx/article/details/12263619)
 最好情况：
 最坏情况：
 */

/*
 *5.归并排序，自顶向下，递归
 */
void merge(int *arr,size_t left,size_t mid,size_t right)
{
    int len = right - left + 1;
    int *temp = new int [len];  //数组较长时请用new，不然栈空间容易溢出
    size_t index = 0;
    size_t i = left, j = mid + 1;
    while(i <= mid && j <= right)
    {
        temp[index++] = arr[i]<= arr[j]? arr[i++]: arr[j++]; //对两边的数组从小到大放入临时空间
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
void divide(int *arr,size_t left,size_t right)
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
void mergesort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    divide(arr,left,right);
}

/*
 1. 6.快速排序
 2. 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 3. 分别对左右递归调用快排
 */
size_t parr [2]; //全局变量，全局变量不好，长期占用内存，每个函数都可访问，容易被修改，函数间相互干扰
void selectmedianofthree(int *arr, size_t left, size_t right)  //找出中间大小的数做哨兵
{
        size_t mid = left + (right - left)/2;  //中部数据的下标
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
                swap(arr[mid],arr[left]);  //把中间大小的数值放到首位
        }
}
void partion(int *arr, size_t left, size_t right)  //数据分段
{
    selectmedianofthree(arr,left,right);  //找出中间大小的哨兵，让分段尽量均匀，提高效率
    size_t lessPnum = 0, largePnum=0;
    int pval = arr[left];  //中间大小的数赋值给哨兵
    int *temp = new int [right-left+1];  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        if(pval < arr[i])  ////比哨兵大的放在右边，从右边末位中间写入，记录下比哨兵大的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    for( ; tempLindex <= tempRindex; ++tempLindex)
    //中间还未被写入的位置，写入哨兵（哨兵可能是多个相同的值）
    {
        temp[tempLindex] = pval;
    }
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[等于哨兵的],[大于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
    parr[0]=lessPnum;
    parr[1]=largePnum;  //可以采用被调用函数的参数引用回传给主函数
}
void qsort(int *arr, size_t left, size_t right, int deep)
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
    else
    {
        partion(arr,left,right);  //数据分段，{[小于哨兵的],[等于哨兵的],[大于哨兵的]}
        size_t pl_index = left + parr[0];  //首位哨兵的下标
        size_t pr_index = right - parr[1];  //末位哨兵的下标
        if(pr_index == right && pl_index != left)  //哨兵群位于数组最右边，且左边还有数据
        {
           qsort(arr,left,pl_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(pl_index == left && pr_index != right)  //哨兵群位于数组最左边，且右边还有数据
        {
            qsort(arr,pr_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else if(pl_index == left && pr_index == right) //全部是哨兵，两侧无数据，退出
        {
            return;
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort(arr,left,pl_index-1,deep);
            qsort(arr,pr_index+1,right,deep);
        }
    }
}
void quicksort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort(arr,left,right,deep);
}

/*
 * 6-1.快速排序(改进：不使用全局变量传递参数)(best version)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */
void selectmedianofthree1(int *arr, size_t left, size_t right)  //找出中间大小的数做哨兵
{
        size_t mid = left + (right - left)/2;  //中部数据的下标
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
                swap(arr[mid],arr[left]);  //把中间大小的数值放到首位
        }
}
void partion1(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)//数据分段
{
    selectmedianofthree1(arr,left,right);  //找出中间大小的哨兵，让分段尽量均匀，提高效率
    int pval = arr[left];  //中间大小的数赋值给哨兵
    int *temp = new int [right-left+1];  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        if(pval < arr[i])  ////比哨兵大的放在右边，从右边末位中间写入，记录下比哨兵大的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    for( ; tempLindex <= tempRindex; ++tempLindex)
    //中间还未被写入的位置，写入哨兵（哨兵可能是多个相同的值）
    {
        temp[tempLindex] = pval;
    }
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[等于哨兵的],[大于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}
void qsort1(int *arr, size_t left, size_t right, int deep)
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
    else if(right-left > 1 && right-left < 20)  //数组长度较小时，调用希尔排序，减少调用快排
    {
        size_t len = right - left + 1;
        shellsort(len, &arr[left]); //数组首地址为&arr[left]
    }
    else
    {
        size_t lessPnum = 0, largePnum=0;
        partion1(arr,left,right,lessPnum,largePnum);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t pl_index = left + lessPnum;  //首位哨兵的下标
        size_t pr_index = right - largePnum;  //末位哨兵的下标
        if(pr_index == right && pl_index != left)  //哨兵群位于数组最右边，且左边还有数据
        {
            qsort1(arr,left,pl_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(pl_index == left && pr_index != right)  //哨兵群位于数组最左边，且右边还有数据
        {
            qsort1(arr,pr_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else if(pl_index == left && pr_index == right) //全部是哨兵，两侧无数据，退出
        {
            return;
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort1(arr,left,pl_index-1,deep);
            qsort1(arr,pr_index+1,right,deep);
        }
    }
}
void quicksort1(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort1(arr,left,right,deep);
}

/*
 * 6-2.快速排序(固定哨兵)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */
void partion2(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)//数据分段
{
    int pval = arr[left];  //左边的数赋值给哨兵
    int *temp = new int [right-left+1]();  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        else  //比哨兵大或等于的放在右边，从右边末位往中间写入，记录下比哨兵大和等的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    temp[tempLindex] = pval;    //把哨兵写到中间的位置
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[大于等于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}
void qsort2(int *arr, size_t left, size_t right, int deep)
{
    if(left >= right)
    {
        return;
    }
    else
    {
        size_t lessPnum = 0, largePnum=0;
        partion2(arr,left,right,lessPnum,largePnum);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t p_index = left + lessPnum;  //哨兵的下标
        if(p_index == right)  //哨兵位于数组最右边，且左边还有数据
        {
            qsort2(arr,left,p_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(p_index == left)  //哨兵位于数组最左边，且右边还有数据
        {
            qsort2(arr,p_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort2(arr,left,p_index-1,deep);
            qsort2(arr,p_index+1,right,deep);
        }
    }
}
void quicksort2(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort2(arr,left,right,deep);
}
/*
 * 6-3.快速排序(随机哨兵)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */
void partion3(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)//数据分段
{
    int pval = arr[rand()%(right-left)+left];  //左边的数赋值给哨兵
    int *temp = new int [right-left+1]();  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        else  //比哨兵大或等于的放在右边，从右边末位往中间写入，记录下比哨兵大和等的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    temp[tempLindex] = pval;    //把哨兵写到中间的位置
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[大于等于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}
void qsort3(int *arr, size_t left, size_t right, int deep)
{
    if(left >= right)
    {
        return;
    }
    else
    {
        size_t lessPnum = 0, largePnum=0;
        partion3(arr,left,right,lessPnum,largePnum);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t p_index = left + lessPnum;  //哨兵的下标
        if(p_index == right)  //哨兵位于数组最右边，且左边还有数据
        {
            qsort3(arr,left,p_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(p_index == left)  //哨兵位于数组最左边，且右边还有数据
        {
            qsort3(arr,p_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort3(arr,left,p_index-1,deep);
            qsort3(arr,p_index+1,right,deep);
        }
    }
}
void quicksort3(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort3(arr,left,right,deep);
}
/*
 * 6-4.快速排序(三数取中，哨兵)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */
void selectmedianofthree4(int *arr, size_t left, size_t right)  //找出中间大小的数做哨兵
{
        size_t mid = left + (right - left)/2;  //中部数据的下标
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
                swap(arr[mid],arr[left]);  //把中间大小的数值放到首位
        }
}
void partion4(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)//数据分段
{
    selectmedianofthree4(arr,left,right);  //找出中间大小的哨兵，让分段尽量均匀，提高效率
    int pval = arr[left];  //中间大小的数赋值给哨兵
    int *temp = new int [right-left+1]();  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        else  //比哨兵大或等于的放在右边，从右边末位往中间写入，记录下比哨兵大和等的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    temp[tempLindex] = pval;    //把哨兵写到中间的位置
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[等于哨兵的],[大于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}
void qsort4(int *arr, size_t left, size_t right, int deep)
{
    if(left >= right)
    {
        return;
    }
    else
    {
        size_t lessPnum = 0, largePnum=0;
        partion4(arr,left,right,lessPnum,largePnum);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t p_index = left + lessPnum;  //哨兵的下标
        if(p_index == right)  //哨兵位于数组最右边，且左边还有数据
        {
            qsort4(arr,left,p_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(p_index == left)  //哨兵位于数组最左边，且右边还有数据
        {
            qsort4(arr,p_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort4(arr,left,p_index-1,deep);
            qsort4(arr,p_index+1,right,deep);
        }
    }
}
void quicksort4(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort4(arr,left,right,deep);
}

/*
 * 6-5.快速排序(三数取中+短数组其他排序)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */
void selectmedianofthree5(int *arr, size_t left, size_t right)  //找出中间大小的数做哨兵
{
        size_t mid = left + (right - left)/2;  //中部数据的下标
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
                swap(arr[mid],arr[left]);  //把中间大小的数值放到首位
        }
}
void partion5(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)//数据分段
{
    selectmedianofthree5(arr,left,right);  //找出中间大小的哨兵，让分段尽量均匀，提高效率
    int pval = arr[left];  //中间大小的数赋值给哨兵
    int *temp = new int [right-left+1];  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        else  //比哨兵大或等于的放在右边，从右边末位往中间写入，记录下比哨兵大和等的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    temp[tempLindex] = pval;    //把哨兵写到中间的位置
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[等于哨兵的],[大于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}
void qsort5(int *arr, size_t left, size_t right, int deep)
{
    if(left >= right)
    {
        return;
    }
    else if(right-left > 0 && right-left < 20)  //数组长度较小时，调用希尔排序，减少调用快排
    {
        size_t len = right - left + 1;
        shellsort(len, &arr[left]); //数组首地址为&arr[left]
    }
    else
    {
        size_t lessPnum = 0, largePnum=0;
        partion5(arr,left,right,lessPnum,largePnum);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t pl_index = left + lessPnum;  //首位哨兵的下标
        size_t pr_index = right - largePnum;  //末位哨兵的下标
        if(pr_index == right && pl_index != left)  //哨兵群位于数组最右边，且左边还有数据
        {
            qsort5(arr,left,pl_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(pl_index == left && pr_index != right)  //哨兵群位于数组最左边，且右边还有数据
        {
            qsort5(arr,pr_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort5(arr,left,pl_index-1,deep);
            qsort5(arr,pr_index+1,right,deep);
        }
    }
}
void quicksort5(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort5(arr,left,right,deep);
}
//产生随机数
void rand4data(int i, size_t dsize, int *arr)
{
    int flag = i%5;
    if (flag == 0)
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            arr[i] = i;
        }
    }
    else if (flag == 1)
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            arr[i] = (int)dsize - i;
        }
    }
    else if (flag == 2)
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            if (i%5 == 0)
            {
                arr[i] = rand();
            }
            else
            {
                arr[i] = 7;
            }
        }
    }
    else
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            arr[i] = rand();
        }
    }
}
void rand4data1(int i, size_t dsize, int *arr)  //全部同样的数
{
    for (size_t i = 0; i != dsize; ++i)
    {
        arr[i] = 6; 
    }
}
void rand4data2(int i, size_t dsize, int *arr)  //升序数组
{
    int val = i;
    for (size_t i = 0; i != dsize; ++i)
    {
        arr[i] = val++; 
    }
}
void rand4data3(int i, size_t dsize, int *arr)  //降序数组
{
    int val = dsize + i;
    for (size_t i = 0; i != dsize; ++i)
    {
        arr[i] = val--; 
    }
}
long getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}
bool right4sorted(const int *arr, size_t dsize)
{
	for (size_t i = 1; i < dsize; ++i)
	{
		if (arr[i-1] > arr[i])
		{
			return false;
		}
	}
	return true;
}
void test4sort(size_t dsize, void (*mysort)(size_t dsize, int *arr))
{
	int *arr = new int[dsize];
	long   total_time = 0;
	for (int i = 0; i != G_CycleTimes; ++i)
	{
		rand4data(i, dsize, arr);
		long start_time = getCurrentTime();
		mysort(dsize, arr);
		long end_time   = getCurrentTime();
		total_time     += end_time - start_time;
		if (!right4sorted(arr, dsize))
		{
			cerr << "sort for ints failed" << endl;
			return;
		}
	}
	cout << "You have completed for sort testing!" << endl;
	cout << "And the total time is "
		<< float(total_time)/1000000.0 << " seconds." << endl;

	delete [] arr;
	arr = NULL;
}
int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort|todo)" << endl;
		return -1;
	}
	else
	{
		size_t dsize = 0;
		if (string(argv[1]) == "small")
		{
			dsize = G_SmallSize;
		}
		else if (string(argv[1]) == "big")
		{
			dsize = G_BigSize;
		}
		else
		{
			cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort|todo)" << endl;
			return -2;
		}
		
		if (string(argv[2]) == "shellsort")
		{
			test4sort(dsize, shellsort);
		}
		else if (string(argv[2]) == "mergesort")
		{
			test4sort(dsize, mergesort);
		}
		else if (string(argv[2]) == "quicksort")
		{
			test4sort(dsize, quicksort);
		}
		else if (string(argv[2]) == "quicksort1")
		{
			test4sort(dsize, quicksort1);
		}
        else if (string(argv[2]) == "quicksort2")
        {
            test4sort(dsize, quicksort2);
        }
        else if (string(argv[2]) == "quicksort3")
        {
            test4sort(dsize, quicksort3);
        }
        else if (string(argv[2]) == "quicksort4")
        {
            test4sort(dsize, quicksort4);
        }
        else if (string(argv[2]) == "quicksort5")
        {
            test4sort(dsize, quicksort5);
        }
		else
		{
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}
