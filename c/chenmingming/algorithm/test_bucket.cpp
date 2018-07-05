#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include <string.h>


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


void bucketsort(size_t dsize, int *arr)
{
    if(dsize == 0)  //预防特殊情况下后面代码失效
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
        int div = ceil((double)(maxval-minval)/space);   //桶的个数，ceil取进位数(先double强转（float的精度不够高），避免丢失小数点)
        //space 太小，桶个数太多，会造成栈空间溢出
        int numsofeachbucket[div];  //开辟数组，存放每个桶内的元素个数
        for(size_t i =0; i != div; ++i)
        {
            numsofeachbucket[i] = 0;    //每个桶的元素个数初始化为0
        }
        //memset(numsofeachbucket, 0, sizeof(numsofeachbucket));    //每个桶内元素个数置0
        //vector<int **p> bucket(div);
        for(size_t i = 0; i != dsize; ++i)
        {
            ++numsofeachbucket[(arr[i]-minval)/space];  //把元素按大小分到不同的桶，并增加该桶元素个数
        }
        int **p = new int* [div];   //开辟堆空间，指针数组，每个元素（指针）指向每个桶的0位
        int **temp = new int* [div];    //临时数组，保存某些指针的初始值，方便delete（delete时，指针必须位于初始位置）
        int **temp_1 = new int* [div];  //同上
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)    //桶内有元素（没有元素就不要申请空间了，如申请了，指针的地址不为NULL，会出问题）
            {
                p[i] = new int [numsofeachbucket[i]];   //指针数组，每个元素（指针）指向每个桶的0位
                temp[i] = p[i]; //记录每个桶申请的空间的初始地址，后面delete temp_1[i]即可删除开辟的p[i] new出的空间
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
                    quicksort(numsofeachbucket[i], temp[i]);   //对动态数组进行快速排序（p[i]挪动过了，temp[i]指向数组首位）
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

void sort(int *arr)
{
    int dsize = 11;
    for(int i=0;i <= 10;++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


	bucketsort(dsize, arr);    



    for(int i=0;i <= 10;++i)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;

}
int main()
{
    int arr1[]={6,5,7,1,3,-6,6,8,4,2,5};
    int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
    int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
    int arr4[]={2,1,1,1,1,1,1,1,1,1,1};
    sort(arr1);
    sort(arr2);
    sort(arr3);
    sort(arr4);
    return 0;
}
