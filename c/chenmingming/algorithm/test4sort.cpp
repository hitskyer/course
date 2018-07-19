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
 * 1.插入排序
 * 每次在末尾插入一个数字，依次向前比较，类似与抓扑克牌(插入排序，每次左边的子序列都是有序的)
 */
void insertsort(size_t dsize, int *arr) //dsize是数组arr的长度
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    for (size_t i = 0; i != dsize; ++i)
    {
        for (size_t j = i; j > 0 && arr[j-1] > arr[j]; --j)
        //每次的子列都是有序的，判断条件可写在for(内)，否则不可（这么做减少运行次数）
        //每次和有序数组最后一个比较，向前搜索，直到找到位置停止
        {
            swap(arr[j-1], arr[j]);
        }
    }
}

/*
 时间复杂度分析
 最好情况：原数列有序，每次放在最后就好了，复杂度为n
 最坏情况：原数列倒序的，每次都要挪到最前面，1+2+...+n-1=n(n-1)/2
 */

/*
 *2.冒泡排序，数从前向后冒泡比较，冒泡过程中，数列无序状态
 */
void bsort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    bool arrisok = false;
    for(size_t i = 0; i != dsize; ++i)
    {
        arrisok = true;
        for(size_t j=1;j <= dsize-1-i;++j)  //后面的数都排好了，所以j<=dsize-1-i,不减i,也可，但时间长
        {
            if(arr[j-1]> arr[j])
            //比较的过程中是无序的，判断条件写在for{}里
            //写在for()里会出现局部条件不满足就退出for循环了，以至于还未排序完
            {
                swap(arr[j-1],arr[j]);
                arrisok = false;  //如果交换过，则数组未完成排序
            }
        }
        if(arrisok == true)
        {
            return; //经过一轮冒泡后,数据没有发生交换则数据为有序，可退出函数，可减少12%时间（用自己的程序）
        }
    }
}

/*
 时间复杂度分析
 最好情况：原数列有序，复杂度为n
 最坏情况：原数列倒序的，每次都要从前挪到后面，n-1+n-2+...+1=n(n-1)/2
 */

/*
 *3.选择排序,每次找出数值最小的下标，交换未排序区域第一个与最小的(与冒泡的区别，只交换一次)
 */
void selecsort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t mindex=0;
    for(size_t i =0; i!= dsize-1; ++i)
    {
        mindex= i ;
        for(size_t j=i+1;j!=dsize;++j)
        {
            if(arr[j]< arr[mindex]) //子列为无序的，判断条件写在for{}里
            {
                mindex = j;     //记录下最小数的下标
            }
        }
        swap(arr[i],arr[mindex]);
    }
}

/*
 时间复杂度分析
 最好情况：（与最坏一样）
 最坏情况：每次都要从前到后比较，n-1+n-2+...+1=n(n-1)/2
 */


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
 * 6-1.快速排序(改进：不使用全局变量传递参数)
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
 * 7.堆排序，建堆（升序建大堆，降序建小堆）
 * 交换堆顶与最后一位无序数据
 * 调整堆，递归，交换调整
 */
void adjust(int *arr, size_t i, size_t dsize)
{
    size_t LowerLeftNode = i*2+1;   //下一层左边的节点
    while(LowerLeftNode < dsize)
    {
        if(LowerLeftNode+1< dsize && arr[LowerLeftNode]< arr[LowerLeftNode+1] )
        {
            ++LowerLeftNode;
        }
        if(arr[i]> arr[LowerLeftNode])  //如果上层节点大于小面两个子节点，结束
        {
            break;
        }
        swap(arr[i], arr[LowerLeftNode]);
        i = LowerLeftNode;  //往下循环调整
        LowerLeftNode = i*2+1;
    }
}
void makeheap(size_t dsize, int *arr)
{
    for(size_t i = dsize/2 -1; i >=0;--i)   //从后往前，底下第二层（第一个有子节点的元素的下标）
    {
        adjust(arr,i,dsize);  //有子节点，调整堆（从i节点往下，末位固定dsize-1）
        if(i == 0)
            break;
    }
}
void heapsort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    makeheap(dsize,arr); //建立堆，大堆，上面父节点比子节点大
    size_t i = 0;
    for(i=dsize-1;i>=0;--i) //从最后一位开始，与堆顶交换，调整堆，尾部数据减1
    {
        swap(arr[i],arr[0]);  //把最大的arr[0]与队尾交换
        adjust(arr,0,i);   //从第0位往下开始调整，末位不固定，数组长度i，每次减一
        if(i == 0)  //i = 0，退出，防止--i，size_t溢出
            break;
    }
}

/*
 *8.计数排序，找出数列中最大最小的数，并记录下每一个元素的个数，然后放回
 */
void countsort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    int index = 0;
    int min, max;
    min = max = arr[0];
    for(int i = 1; i<dsize;++i)
    {
        min=(arr[i] < min)? arr[i] : min;
        max=(arr[i] > max)? arr[i] : max;
    }
    //创建新的数组存放
    int k = max -min +1;
    int *temp = new int [k]();  //（）初始化为0
    for(int i = 0;i< dsize;++i)
    {
        ++temp[arr[i]-min]; //记录每个数的个数，存入数组
    }
    for(int i = min; i <= max;++i)
    {
        for(int j = 0; j < temp[i-min];++j) //存放元素个数不为0的，才进入循环
        {
            arr[index++] = i;  //把元素值写回数组
        }
    }
    delete [] temp;
    temp = NULL;
}

/*
 *9.桶排序，将数据按规则分组，对各小组再分别排序
 */
void bucketsort(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    int maxval = arr[0];
    int minval = arr[0];
    for(int i = 0; i != dsize; ++i) //遍历数组，找出最大最小元素
    {
        maxval = maxval > arr[i] ? maxval : arr[i];
        minval = minval < arr[i] ? minval : arr[i];
    }
    if(maxval == minval)    //如果最大==最小，数组不需要排序（排除下面div=0，进不了位，div总是为0）
    {
        return;
    }
    else
    {
        int space = 10000;  //每个桶数元素值的最大差值（区间大小）
        int div = ceil((double)(maxval-minval)/space);
        //桶的个数，ceil取进位数(先double强转（float的精度不够高），避免丢失小数点)
        //space 太小，桶个数太多，会造成栈空间溢出
        int numsofeachbucket[div];  //开辟数组，存放每个桶内的元素个数
        //知识点：
        //1.桶的个数跟数据相关，space是固定的，但是桶的个数会根据环境变化，不能确保程序在其他环境下正确运行
        //2.div很大时，int numsofeachbucket[div]，直接撑爆栈空间，需要采用new 开辟堆空间
        //3.当(maxval-minval)是space的整数倍的时候，段错误，访问越界
        //第3个问题改成int div = floor((double)(maxval-minval)/space)+1;即可
        for(size_t i =0; i != div; ++i)
        {
            numsofeachbucket[i] = 0;    //每个桶的元素个数初始化为0
        }
        for(size_t i = 0; i != dsize; ++i)
        {
            ++numsofeachbucket[(arr[i]-minval)/space];  //把元素按大小分到不同的桶，并增加该桶元素个数
        }
        int **p = new int* [div];   //开辟堆空间，指针数组，每个元素（指针）指向每个桶的0位
        int **temp = new int* [div];
        //临时数组，保存某些指针的初始值，方便delete（delete时，指针必须位于初始位置）
        int **temp_1 = new int* [div];
        //同上（改进启发：数组长度是一定的，申请一次内存，知道每个桶始末位置即可）
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)
            //桶内有元素（没有元素就不要申请空间了，如申请了，指针的地址是不为NULL的，会出问题）
            {
                p[i] = new int [numsofeachbucket[i]];   //指针数组，每个元素（指针）指向每个桶的0位
                temp[i] = p[i];
                //记录每个桶申请的空间的初始地址，后面delete temp_1[i]即可删除开辟的p[i] new出的空间
                temp_1[i] = p[i];   //记录初始地址，后面p[i],temp[i]（指针）也要挪动
            }
            else
            {
                p[i] = NULL;    //没有元素的桶，不申请空间，指针初始化为NULL
                temp[i] = NULL;
                temp_1[i] = NULL;
            }
        }
        for(size_t i = 0; i != dsize; ++i)
        {
            size_t bucketidx = (arr[i]-minval)/space;   //遍历数组，每个元素的桶号
            *p[bucketidx] = arr[i]; //把每个元素写入对应的桶中
            ++p[bucketidx]; //该桶指针后移一位
        }
        size_t idx = 0; //之前用了static，下次调用的时候idx不会被赋值 =0 操作
        //cout << "static idx " << idx << endl;
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)    //桶非空
            {
                if(numsofeachbucket[i]>1)   //桶元素个数2个或更多
                {
                    quicksort(numsofeachbucket[i], temp[i]);
                    //对动态数组进行快速排序（p[i]挪动过了，temp[i]指向数组首位）
                }
                for(size_t j = 0; j != numsofeachbucket[i]; ++j)
                {
                    arr[idx++] = *temp[i];  //对排序后的数组（1个元素不需排序），写入原数组
                    ++temp[i];
                    //cout << "static idx " << idx << endl;
                }
            }
        }
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)    //对申请出来的空间，释放掉
            {
                delete [] temp_1[i];    //上面每个桶的数组初始位置指针p[i],temp[i]都动过了，所以用此副本初始地址
                temp_1[i] = NULL;       //被释放的空间的相关的指针置为空
                temp[i] = NULL;
                p[i] = NULL;
            }
        }
        delete [] temp_1;   //delete 与 new 配对出现，释放数组，指针置NULL
        delete [] temp;     //内存检测工具valgrind    http://valgrind.org/
        delete [] p;
        temp_1 = NULL;
        temp = NULL;
        p = NULL;
    }
}

/*
 *9.1桶排序(改进)，将数据按规则分组，对各小组再分别排序
 */
void bucketsort1(size_t dsize, int *arr)
{
    if(dsize <= 1)	//预防特殊情况下后面代码失效
    {
        return;
    }
    int maxval = arr[0];
    int minval = arr[0];
    for(int i = 0; i != dsize; ++i)	//遍历数组，找出最大最小元素
    {
        maxval = maxval > arr[i] ? maxval : arr[i];
        minval = minval < arr[i] ? minval : arr[i];
    }
    if(maxval == minval)	//如果最大==最小，数组不需要排序（排除下面div=0，进不了位，div总是为0）
    {
        return;
    }
    else
    {
        int div = 1000;
        int space = (maxval-minval)/div+1;
        //桶的个数，ceil取进位数(先double强转（float的精度不够高），避免丢失小数点)
        //space 太小，桶个数太多，会造成栈空间溢出
        int *numsofeachbucket = new int [div]();
        int *endpositionofeachbucket = new int [div]();	//开辟数组，存放每个桶内的元素个数
        //知识点：
        //1.桶的个数跟数据相关，space是固定的，但是桶的个数会根据环境变化，不能确保程序在其他环境下正确运行
        //2.div很大时，int numsofeachbucket[div]，直接撑爆栈空间，需要采用new 开辟堆空间
        //3.当(maxval-minval)是space的整数倍的时候，段错误，访问越界
        //第3个问题改成int div = floor((double)(maxval-minval)/space)+1;即可

        for(size_t i = 0; i != dsize; ++i)
        {
            ++numsofeachbucket[(arr[i]-minval)/space];  //把元素按大小分到不同的桶，并增加该桶元素个数
            ++endpositionofeachbucket[(arr[i]-minval)/space];
        }
        for(int i = 1; i != div; ++i)
		{
			endpositionofeachbucket[i] += endpositionofeachbucket[i-1];
			//每个桶区间的最大下标+1的值（现在存储的是下标区间的上限+1）
		}
		int *temparr = new int [dsize];	//开辟堆空间，指针数组，每个元素（指针）指向每个桶的0位
        for(size_t i = 0; i != dsize; ++i)
        {
            temparr[--endpositionofeachbucket[(arr[i]-minval)/space]] = arr[i];
            //遍历数组，把每个元素写入对应的桶中
            //运行完成后endpositionofeachbucket[i]就是该桶的首位
        }
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] > 1)	//桶非空
            {
                quicksort(numsofeachbucket[i], &temparr[endpositionofeachbucket[i]]);
                //对动态数组进行快速排序（p[i]挪动过了，temp[i]指向数组首位）
            }
        }
        for(size_t i = 0; i != dsize; ++i)
        {
            arr[i] = temparr[i];	//对排序后的数组（1个元素不需排序），写入原数组
        }
        delete [] numsofeachbucket;	//delete 与 new 配对出现，释放数组，指针置NULL
        delete [] endpositionofeachbucket;		//内存检测工具valgrind	http://valgrind.org/
        delete [] temparr;
        numsofeachbucket = NULL;
        endpositionofeachbucket = NULL;
        temparr = NULL;
    }
}
/*
 *10.基数排序
 */
void radix_countsort(size_t dsize, int *arr, int exp)
{
    int numofeachbucket[10] = {0};  //十个数位，每个桶上有0个元素
    for(int i = 0; i != dsize; ++i)
    {
        ++numofeachbucket[(arr[i]/exp)%10]; //记录该数位上相同的元素个数
    }
    for(int i = 1; i < 10; ++i)
    {
        numofeachbucket[i] += numofeachbucket[i-1];
        //每个位数区间的最大下标+1的值（现在存储的是下标区间的上限+1）
    }
    int *output = new int [dsize];
    for(int i = dsize-1; i >= 0; --i)
    {
        output[--numofeachbucket[(arr[i]/exp)%10]] = arr[i]; //把数组放在不同的区间位置上
    }
    for(int i = 0; i != dsize; ++i)
    {
        arr[i] = output[i];  //一个数位排好后，写回原数组
    }
    delete [] output;
    output = NULL;
}
void radixsort(size_t dsize, int *arr)
{
    if(dsize <= 1)
    {
        return;
    }
    int maxval = arr[0];
    for(size_t i = 0; i != dsize; ++i)
    {
        maxval = arr[i] > maxval ? arr[i] : maxval; //找出最大的数
    }
    for(int exp = 1; maxval/exp > 0; exp *= 10) //从最低位开始对每个数位进行排序
    {
        radix_countsort(dsize, arr, exp);
    }
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
		if (string(argv[2]) == "insertsort")
		{
			test4sort(dsize, insertsort);
		}
		else if (string(argv[2]) == "bsort")
		{
			test4sort(dsize, bsort);
		}
		else if (string(argv[2]) == "selecsort")
		{
			test4sort(dsize, selecsort);
		}
		else if (string(argv[2]) == "shellsort")
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
		else if (string(argv[2]) == "heapsort")
		{
			test4sort(dsize, heapsort);
		}
		else if (string(argv[2]) == "countsort")
		{
			test4sort(dsize, countsort);
		}
		else if (string(argv[2]) == "bucketsort")
		{
			test4sort(dsize, bucketsort);
		}
		else if (string(argv[2]) == "bucketsort1")
		{
			test4sort(dsize, bucketsort1);
		}
		else if (string(argv[2]) == "radixsort")
		{
			test4sort(dsize, radixsort);
		}
		else
		{
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}
