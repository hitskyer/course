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
    if(dsize == 0)
    {
        return;
    }
    int maxval = arr[0];
    int minval = arr[0];
    for(int i = 0; i != dsize; ++i)
    {
        maxval = maxval > arr[i] ? maxval : arr[i];
        minval = minval < arr[i] ? minval : arr[i];
    }
    if(maxval == minval)
    {
        return;
    }
    else
    {
        int space = 100000;  //每个桶数值最大差值
        int div = ceil((float)(maxval-minval)/space);   //桶的个数，ceil取进位数(先float强转，避免丢失小数点)
        int numsofeachbucket[div];
        for(size_t i =0; i != div; ++i)
        {
            numsofeachbucket[i] = 0;
        }
        //memset(numsofeachbucket, 0, sizeof(numsofeachbucket));    //每个桶内元素个数置0
        //vector<int **p> bucket(div);
        for(size_t i = 0; i != dsize; ++i)
        {
            ++numsofeachbucket[(arr[i]-minval)/space];  //把元素按大小分到不同的桶
        }
        int **p = new int* [div];
        int **temp = new int* [div];
        int **temp_1 = new int* [div];
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)
            {
                p[i] = new int [numsofeachbucket[i]];
                temp[i] = p[i];
                temp_1[i] = p[i];
            }
            else
            {
                p[i] = NULL;
                temp[i] = NULL;
                temp_1[i] = NULL;
            }
        }
        for(size_t i = 0; i != dsize; ++i)
        {
            size_t bucketidx = (arr[i]-minval)/space;
            *p[bucketidx] = arr[i];
            ++p[bucketidx];
        }
            //p = p - numsofeachbucket[j];  //动态数组的指针不可修改，否则delete时会报错
        size_t idx = 0;
        //cout << "static idx " << idx << endl;
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)
            {
                if(numsofeachbucket[i]>1)
                {
                    quicksort(numsofeachbucket[i], temp[i]);   //对动态数组进行排序
                }
                for(size_t j = 0; j != numsofeachbucket[i]; ++j)
                {
                    arr[idx++] = *temp[i];
                    ++temp[i];
                    //cout << "static idx " << idx << endl;
                }
            }
        }
        for(size_t i = 0; i != div; ++i)
        {
            if(numsofeachbucket[i] != 0)
            {
                delete [] temp_1[i];
                temp_1[i] = NULL;
                temp[i] = NULL;
                p[i] = NULL;
            }
        }
        delete [] temp_1;
        delete [] temp;
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
