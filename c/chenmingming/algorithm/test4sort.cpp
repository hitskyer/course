#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
const size_t G_BigSize    = 1000000;
const size_t G_SmallSize  = 1000;
const int    G_CycleTimes = 1000;

/*
 * 冒泡排序(bubble sort)，做一个例子使用
 * 每次在末尾插入一个数字，依次向前冒泡(应该叫插入排序，每次的子序列都是有序的)
 */
void bsort(const int * iarr, size_t dsize, int *oarr) {
	for (size_t i = 0; i != dsize; ++i) {
		oarr[i] = iarr[i];
		for (size_t j = i; j > 0 && oarr[j-1] > oarr[j]; --j) {
			swap(oarr[j-1], oarr[j]);
		}
	}
}
/*
 *每次在队首插入数字，其他数向后平移，从前向后冒泡比较
 */
void bsort1(const int *iarr, size_t dsize, int *oarr)
{
	for(size_t i = 0;i != dsize;++i)
	{	oarr[0]= iarr[i];
		for(size_t j=1;j <= i && oarr[j-1] > oarr[j];++j)	//每次的子列都是有序的，判断条件可写在for内，否则不可
		{	swap(oarr[j-1],oarr[j]);
		}
		if(i != (dsize-1))
		{	for(size_t j= i;j >= 0;--j)	//数据平移把第一位让出来
			{	oarr[j+1]= oarr[j];
				if(j==0)	//防止 --j溢出
					break;
			}
		}
	}
}
/*
 *选择排序,每次找出数值最小的下标，交换未排序区域第一个与最小的
 */
void selecsort(const int *iarr, size_t dsize, int *oarr)
{
	for(size_t i = 0;i != dsize;++i)
	{	oarr[i]= iarr[i];	//iarr是不可修改的，复制出来给oarr
	}
	size_t mindex=0;
	for(size_t i =0 ;i!= dsize-1;++i)
	{	mindex= i ;
		for(size_t j=i+1;j!=dsize;++j)
		{	if(oarr[j]< oarr[mindex])	//子列为无序的，判断条件写在for{}里
			{	mindex = j;		//记录下最小数的下标
			}
		}
		swap(oarr[i],oarr[mindex]);
	}
}
/*
 * 希尔排序，分组
 */
void shellsort(const int *iarr, size_t dsize, int *oarr)
{
	size_t gap = 1;
	size_t j=0;
	for(gap=dsize/2;gap> 0;gap /= 2)
	{	for(size_t i = gap;i < dsize;++i)
		{	j = i;
			for(;j-gap>=0 && oarr[j-gap]> oarr[j];j -= gap)
			{	swap(oarr[j-gap],oarr[j]);}
		}
		
	}
}
/*
 *归并排序，自顶向下，递归
 */
void merge(int *oarr,size_t left,size_t mid,size_t right)
{
	int len = right - left + 1;
	int *temp = new int [len];
	size_t index = 0;
	size_t i = left, j = mid + 1;
	while(i <= mid && j <= right)
	{
		temp[index++] = oarr[i]<= oarr[j]? oarr[i++]: oarr[j++];
	}
	while(i <= mid)		{temp[index++]= oarr[i++];}
	while(j <= right)	{temp[index++]= oarr[j++];}
	for(int k = 0;k< len;++k)
	{
		oarr[left++ ]= temp[k];
	}
	delete [] temp;
	temp = NULL;
}

void divide(int *oarr,size_t left,size_t right)
{
        if(left == right)
                return;
        size_t mid = (left+right)/2;

        divide(oarr,left,mid);
        divide(oarr,mid+1,right);
	merge(oarr,left,mid,right);
}

void mergesort(const int *iarr, size_t dsize, int *oarr)
{
	for(size_t i = 0;i != dsize;++i)
        {       oarr[i]= iarr[i];       //iarr是不可修改的，复制出来给oarr
        }
	size_t left = 0, right = dsize-1;
	divide(oarr,left = 0,right = dsize-1);
}
//产生随机数
void rand4data(int i, size_t dsize, int *iarr) {
	int flag = i%5;
	if (flag == 0) {
		for (size_t i = 0; i != dsize; ++i) {
			iarr[i] = i;
		}
	} else if (flag == 1) {
		for (size_t i = 0; i != dsize; ++i) {
			iarr[i] = (int)dsize - i;
		}
	} else {
		for (size_t i = 0; i != dsize; ++i) {
			iarr[i] = rand();
		}
	}
}
long getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}
bool right4sorted(const int *oarr, size_t dsize) {
	for (size_t i = 1; i < dsize; ++i) {
		if (oarr[i-1] > oarr[i]) {
			return false;
		}
	}
	return true;
}
void test4sort(size_t dsize, void (*mysort)(const int *iarr, size_t dsize, int *oarr)) {
	int *iarr         = new int[dsize];
	int *oarr         = new int[dsize];
	long   total_time = 0;
	
	for (int i = 0; i != G_CycleTimes; ++i) {
		rand4data(i, dsize, iarr);
		
		long start_time = getCurrentTime();
		mysort(iarr, dsize, oarr);
		long end_time   = getCurrentTime();
		total_time     += end_time - start_time;
		
		if (!right4sorted(oarr, dsize)) {
			cerr << "sort for ints failed" << endl;
			return;
		}
	}
	cout << "You have completed for sort testing!" << endl;
	cout << "And the total time is " 
		<< float(total_time)/1000000.0 << " seconds." << endl;

	delete [] iarr;
	delete [] oarr;
	iarr = NULL;
	oarr = NULL;
}
int main(int argc, char *argv[]) {
	if (argc < 3) {
		cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort|todo)" << endl;
		return -1;
	} else {
		size_t dsize = 0;
		if (string(argv[1]) == "small") {
			dsize = G_SmallSize;
		} else if (string(argv[1]) == "big") {
			dsize = G_BigSize;
		} else {
			cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort|todo)" << endl;
			return -2;
		}
		if (string(argv[2]) == "bsort") {
			test4sort(dsize, bsort);}
		else if (string(argv[2]) == "bsort1")
		{
			test4sort(dsize, bsort1);
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
		else {
			cerr << "unknown method for sorting : " << argv[2] << endl;
			return -3;
		}
	}
}
