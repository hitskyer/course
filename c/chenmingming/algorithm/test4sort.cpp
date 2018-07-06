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
 * 插入排序
 * 每次在末尾插入一个数字，依次向前比较，类似与抓扑克牌(插入排序，每次左边的子序列都是有序的)
 */
void insertsort(size_t dsize, int *arr) 
{
	for (size_t i = 0; i != dsize; ++i) 
	{
		for (size_t j = i; j > 0 && arr[j-1] > arr[j]; --j)	//每次的子列都是有序的，判断条件可写在for(内)，否则不可 
		{
			swap(arr[j-1], arr[j]);
		}
	}
}
/*
 *冒泡排序，数从前向后冒泡比较，冒泡过程中，数列无序状态
 */
void bsort(size_t dsize, int *arr)
{
	for(size_t i = 0; i != dsize; ++i)
	{	
		for(size_t j=1;j <= dsize-1-i;++j)	//后面的数都排好了，所以j<=dsize-1-i,不减i,也可以，但时间长
		{	
			if(arr[j-1]> arr[j])	//比较的过程中是无序的，判断条件写在for{}里，写在for()里会出现局部条件不满足就退出for循环了，以至于还未排序完
				swap(arr[j-1],arr[j]);
		}
	}
}
/*
 *选择排序,每次找出数值最小的下标，交换未排序区域第一个与最小的(与冒泡的区别，只交换一次)
 */
void selecsort(size_t dsize, int *arr)
{
	size_t mindex=0;
	for(size_t i =0 ;i!= dsize-1;++i)
	{	
		mindex= i ;
		for(size_t j=i+1;j!=dsize;++j)
		{	if(arr[j]< arr[mindex])	//子列为无序的，判断条件写在for{}里
			{	mindex = j;		//记录下最小数的下标
			}
		}
		swap(arr[i],arr[mindex]);
	}
}
/*
 * 希尔排序，分组插入排序，相隔gap个数的都为一组，从第gap个数开始（相当于每组数的第一个）
 */
void shellsort(size_t dsize, int *arr)
{
	size_t gap = 1;
	size_t j=0;
	for(gap=dsize/2;gap> 0;gap /= 2)
	{	
		for(size_t i = gap;i < dsize;++i)
		{	
			for(j=i;int(j-gap)>=0 && arr[j-gap]> arr[j];j -= gap)	//int()转换类型，避免溢出
			{
				swap(arr[j-gap],arr[j]);
			}
		}
		
	}
}
/*
 *归并排序，自顶向下，递归
 */
void merge(int *arr,size_t left,size_t mid,size_t right)
{
	int len = right - left + 1;
	int *temp = new int [len];
	size_t index = 0;
	size_t i = left, j = mid + 1;
	while(i <= mid && j <= right)
	{
		temp[index++] = arr[i]<= arr[j]? arr[i++]: arr[j++];
	}
	while(i <= mid)		{temp[index++]= arr[i++];}
	while(j <= right)	{temp[index++]= arr[j++];}
	for(int k = 0;k< len;++k)
	{
		arr[left++ ]= temp[k];
	}
	delete [] temp;
	temp = NULL;
}

void divide(int *arr,size_t left,size_t right)
{
        if(left == right)
                return;
        size_t mid = (left+right)/2;

        divide(arr,left,mid);
        divide(arr,mid+1,right);
	merge(arr,left,mid,right);
}

void mergesort(size_t dsize, int *arr)
{
	size_t left = 0, right = dsize-1;
	divide(arr,left,right);
}
/*
 * 快速排序
 */
size_t parr [2];
void selectmedianofthree(int *arr, size_t left, size_t right)
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

size_t partion(int *arr, size_t left, size_t right)
{
    selectmedianofthree(arr,left,right);

    size_t lessPnum = 0, largePnum=0;
    int pval = arr[left];
//    cout << "pval " << pval << endl;
    int *temp = new int [right-left+1];
    int tempLindex=0, tempRindex = right-left;
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i])
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        if(pval < arr[i])
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    for( ; tempLindex <= tempRindex; ++tempLindex)
    {
        temp[tempLindex] = pval;
    }
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++];
        // cout << arr[i] << " " ;
    }
    delete [] temp;
    temp = NULL;
    parr[0]=lessPnum;
    parr[1]=largePnum;
//    cout << "lessPnum " << parr[0] << endl;
//    cout << "largePnum " << parr[1] << endl;
}
void qsort(int *arr, size_t left, size_t right, int deep)
{
	if(left >= right)
    {
        return;
    }
    else if(right-left == 1)
    {
        if(arr[left]>arr[right])
        {        
        	swap(arr[left], arr[right]);
        }

    }
    else
    {
        partion(arr,left,right);
        size_t pl_index = left + parr[0];
        size_t pr_index = right - parr[1];
//      cout << "left " << left << "pl_index " << pl_index
//           <<" pr_index " << pr_index << " right " << right << endl;

        if(pr_index == right && pl_index != left)
        {
//		cout << "deep is " << ++deep << endl;
	       qsort(arr,left,pl_index-1,deep);
        }
        else if(pl_index == left && pr_index != right)
        {       
//		cout << "deep is " << ++deep << endl;
			qsort(arr,pr_index+1,right,deep);
        }
        else if(pl_index == left && pr_index == right)
        {
            return;
        }
        else
        {
//			cout << "deep is " << ++deep << endl;
            qsort(arr,left,pl_index-1,deep);
            qsort(arr,pr_index+1,right,deep);
        }
    }
}
void quicksort(size_t dsize, int *arr)
{
	if(dsize > 0)
    {
        size_t left = 0, right = dsize-1;
    	int deep = 0;
    	qsort(arr,left,right,deep);
	}
    else
    {
        return;
    }
}
/*
 * 堆排序，建堆（升序建大堆，降序建小堆）
 * 交换堆定与最后的数据
 * 调整，递归交换调整
 */
void adjust(int *arr, size_t i, size_t dsize)
{
	size_t LowerLeftNode = i*2+1;	//下一层左边的节点
	while(LowerLeftNode < dsize)
	{
		if(LowerLeftNode+1< dsize && arr[LowerLeftNode]< arr[LowerLeftNode+1] )
		{
			++LowerLeftNode;
		}
		if(arr[i]> arr[LowerLeftNode])
		{
			break;
		}
		swap(arr[i], arr[LowerLeftNode]);
		i = LowerLeftNode;
		LowerLeftNode = i*2+1;
	}
}
void makeheap(size_t dsize, int *arr)
{
	size_t i = 0;
	for(size_t i = dsize/2 -1; i >=0;--i)	//底下第二层
	{
		adjust(arr,i,dsize);
		if(i == 0)
			break;
	}
}
void heapsort(size_t dsize, int *arr)
{
	makeheap(dsize,arr);
	size_t i = 0;
	for(i=dsize-1;i>=0;--i)
	{
		swap(arr[i],arr[0]);
		adjust(arr,0,i);
		if(i == 0)
			break;
	}
}
/*
 *计数排序，找出数列中最大最下的数，并记录下每一个元素的个数，然后放回
 */
void countsort(size_t dsize, int *arr)
{
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
	int *temp = new int [k]();	//（）初始化为0
	for(int i = 0;i< dsize;++i)
	{
		++temp[arr[i]-min];	//记录每个数的个数，存入数组
	}
	for(int i = min; i <= max;++i)
	{
		for(int j = 0; j < temp[i-min];++j)	//不为0的，才进入循环
		{
			arr[index++] = i;
		}
	}
	delete [] temp;
	temp = NULL;
}
/*
 *桶排序，将数据按规则分组，对各小组再分别排序
 */
void bucketsort(size_t dsize, int *arr)
{
    if(dsize == 0)	//预防特殊情况下后面代码失效
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
        int space = 10000;  //每个桶数元素值的最大差值（区间大小）
        int div = ceil((double)(maxval-minval)/space);   //桶的个数，ceil取进位数(先double强转（float的精度不够高），避免丢失小数点)
        //space 太小，桶个数太多，会造成栈空间溢出
        int numsofeachbucket[div];	//开辟数组，存放每个桶内的元素个数
        for(size_t i =0; i != div; ++i)
        {
            numsofeachbucket[i] = 0;	//每个桶的元素个数初始化为0
        }
        //memset(numsofeachbucket, 0, sizeof(numsofeachbucket));    //每个桶内元素个数置0
        //vector<int **p> bucket(div);
        for(size_t i = 0; i != dsize; ++i)
        {
            ++numsofeachbucket[(arr[i]-minval)/space];  //把元素按大小分到不同的桶，并增加该桶元素个数
        }
        int **p = new int* [div];	//开辟堆空间，指针数组，每个元素（指针）指向每个桶的0位
        int **temp = new int* [div];	//临时数组，保存某些指针的初始值，方便delete（delete时，指针必须位于初始位置）
        int **temp_1 = new int* [div];	//同上
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)	//桶内有元素（没有元素就不要申请空间了，如申请了，指针的地址不为NULL，会出问题）
            {
                p[i] = new int [numsofeachbucket[i]];	//指针数组，每个元素（指针）指向每个桶的0位
                temp[i] = p[i];	//记录每个桶申请的空间的初始地址，后面delete temp_1[i]即可删除开辟的p[i] new出的空间
                temp_1[i] = p[i];	//记录初始地址，后面p[i],temp[i]（指针）也要挪动
            }
            else
            {
                p[i] = NULL;	//没有元素的桶，不申请空间，指针初始化为NULL
                temp[i] = NULL;
                temp_1[i] = NULL;
            }
        }
        for(size_t i = 0; i != dsize; ++i)
        {
            size_t bucketidx = (arr[i]-minval)/space;	//遍历数组，每个元素的桶号
            *p[bucketidx] = arr[i];	//把每个元素写入对应的桶中
            ++p[bucketidx];	//该桶指针后移一位
        }
        size_t idx = 0;	//之前用了static，下次调用的时候idx不会被赋值 =0 操作
        //cout << "static idx " << idx << endl;
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)	//桶非空
            {
                if(numsofeachbucket[i]>1)	//桶元素个数2个或更多
                {
                    quicksort(numsofeachbucket[i], temp[i]);   //对动态数组进行快速排序（p[i]挪动过了，temp[i]指向数组首位）
                }
                for(size_t j = 0; j != numsofeachbucket[i]; ++j)
                {
                    arr[idx++] = *temp[i];	//对排序后的数组（1个元素不需排序），写入原数组
                    ++temp[i];
                    //cout << "static idx " << idx << endl;
                }
            }
        }
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)	//对申请出来的空间，释放掉
            {
                delete [] temp_1[i];	//上面每个桶的数组初始位置指针p[i],temp[i]都动过了，所以用此副本初始地址
                temp_1[i] = NULL;		//被释放的空间的相关的指针置为空
                temp[i] = NULL;
                p[i] = NULL;
            }
        }
        delete [] temp_1;	//delete 与 new 配对出现，释放数组，指针置NULL
        delete [] temp;		//内存检测工具valgrind	http://valgrind.org/
        delete [] p;
        temp_1 = NULL;
        temp = NULL;
        p = NULL;
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
	int *arr         = new int[dsize];
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
		else 
		{
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}
