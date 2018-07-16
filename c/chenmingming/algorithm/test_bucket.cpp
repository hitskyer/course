#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include <string.h>


/*
 * 6.快速排序(改进：不使用全局变量传递参数)
 */
//size_t parr [2];
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

size_t partion(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)
{
    selectmedianofthree(arr,left,right);

//   size_t lessPnum = 0, largePnum=0;
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
//    parr[0]=lessPnum;
//    parr[1]=largePnum;
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
    	size_t lessPnum = 0, largePnum=0;
        partion(arr,left,right,lessPnum,largePnum);
        size_t pl_index = left + lessPnum;
        size_t pr_index = right - largePnum;
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
        int div = 5;
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

void sort(int *arr)
{
    int dsize = 11;
    for(int i=0;i <= 10;++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


	bucketsort1(dsize, arr);    



    for(int i=0;i <= 10;++i)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;

}
int main()
{
    int arr1[]={6,5,7,1,3,0,6,8,4,10,5};
    int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
    int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
    int arr4[]={1,1,1,1,1,1,1,1,1,1,-5};
    sort(arr1);
    sort(arr2);
    sort(arr3);
    sort(arr4);
    return 0;
}
