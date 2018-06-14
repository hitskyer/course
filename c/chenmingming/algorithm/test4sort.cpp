#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
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
void qsort(int *arr, size_t left, size_t right)
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
//        cout << "left " << left << "pl_index " << pl_index
//             <<" pr_index " << pr_index << " right " << right << endl;

        if(pr_index == right && pl_index != left)
        {       qsort(arr,left,pl_index-1);
        }
        else if(pl_index == left && pr_index != right)
        {       qsort(arr,pr_index+1,right);
        }
        else if(pl_index == left && pr_index == right)
        {
            return;
        }
        else
        {
            qsort(arr,left,pl_index-1);
            qsort(arr,pr_index+1,right);
        }
    }
}
void quicksort(size_t dsize, int *arr)
{
	size_t left = 0, right = dsize-1;
	qsort(arr,left,right);
	
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

long getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}
bool right4sorted(const int *arr, size_t dsize) {
	for (size_t i = 1; i < dsize; ++i) {
		if (arr[i-1] > arr[i]) {
			return false;
		}
	}
	return true;
}
void test4sort(size_t dsize, void (*mysort)(size_t dsize, int *arr)) 
{
	int *arr         = new int[dsize];
	long   total_time = 0;
	
	for (int i = 0; i != G_CycleTimes; ++i) {
		rand4data(i, dsize, arr);
		
		long start_time = getCurrentTime();
		mysort(dsize, arr);
		long end_time   = getCurrentTime();
		total_time     += end_time - start_time;
		
		if (!right4sorted(arr, dsize)) {
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
		else 
		{
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}
