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
 * 6-1.快速排序(改进：不使用全局变量传递参数)(best version)(三数取中基准+希尔排序+基准群)
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
 * 6-1-opti1.快速排序(best version)(三数取中基准+希尔排序+基准群)(opti1,只申请一次内存)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */

void partion1_opti1(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum, int *temp)//数据分段
{
    selectmedianofthree1(arr,left,right);  //找出中间大小的哨兵，让分段尽量均匀，提高效率
    int pval = arr[left];  //中间大小的数赋值给哨兵
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
}
void qsort1_opti1(int *arr, size_t left, size_t right, int deep, int *temp)
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
        partion1_opti1(arr,left,right,lessPnum,largePnum,temp);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t pl_index = left + lessPnum;  //首位哨兵的下标
        size_t pr_index = right - largePnum;  //末位哨兵的下标
        if(pr_index == right && pl_index != left)  //哨兵群位于数组最右边，且左边还有数据
        {
            qsort1_opti1(arr,left,pl_index-1,deep,temp); //只对左边非哨兵数据快排
        }
        else if(pl_index == left && pr_index != right)  //哨兵群位于数组最左边，且右边还有数据
        {
            qsort1_opti1(arr,pr_index+1,right,deep,temp);  //只对右边非哨兵数据快排
        }
        else if(pl_index == left && pr_index == right) //全部是哨兵，两侧无数据，退出
        {
            return;
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort1_opti1(arr,left,pl_index-1,deep,temp);
            qsort1_opti1(arr,pr_index+1,right,deep,temp);
        }
    }
}
void quicksort1_opti1(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    int *temp = new int [dsize];  //一次性开辟堆空间存放临时数组
    qsort1_opti1(arr,left,right,deep,temp);
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}

/*
 * 6-1-opti2.快速排序(best version)(三数取中基准+希尔排序+基准群)(不申请内存)
 * 对数组找出一个中间大小的合适哨兵，把小于哨兵的放左边，大于哨兵的放右边，中间是等于哨兵的
 * 分别对左右递归调用快排
 */
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
    for(i = pindex-1; i >= left; --i)
    {
        if(arr[i] == pval)
        {
            ++leftpnum;
            pl_index = pindex - leftpnum;
            swap(arr[i],arr[pl_index]);   
        }
    }
    for(i = pindex+1; i <= right; ++i)
    {
        if(arr[i] == pval)
        {
            ++rightpnum;
            pr_index = pindex + rightpnum;
            swap(arr[i],arr[pr_index]);  
        }
    }
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
    else if(right-left > 1 && right-left < 20)  //数组长度较小时，调用希尔排序，减少调用快排
    {
        size_t len = right - left + 1;
        shellsort(len, &arr[left]); //数组首地址为&arr[left]
    }
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
		else if (string(argv[2]) == "quicksort1")
		{
			test4sort(dsize, quicksort1);
		}
        else if (string(argv[2]) == "quicksort1_opti1")
        {
            test4sort(dsize, quicksort1_opti1);
        }
        else if (string(argv[2]) == "quicksort1_opti2")
        {
            test4sort(dsize, quicksort1_opti2);
        }
        else
		{
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}
