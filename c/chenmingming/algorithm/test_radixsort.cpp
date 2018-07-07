#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include <string.h>

void radix_countsort(size_t dsize, int *arr, int exp)
{
	int numofeachbucket[10] = {0};
	for(int i = 0; i != dsize; ++i)
	{
		++numofeachbucket[(arr[i]/exp)%10];	//记录该数位上相同的元素个数
	}
	for(int i = 1; i < 10; ++i)
	{
		numofeachbucket[i] += numofeachbucket[i-1]; //每个位数区间的最大序号+1的值
	}
	int *output = new int [dsize];
	for(int i = dsize-1; i >= 0; --i)
	{
		output[--numofeachbucket[(arr[i]/exp)%10]] = arr[i];
	}
	for(int i = 0; i != dsize; ++i)
	{
		arr[i] = output[i];
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
    	maxval = arr[i] > maxval ? arr[i] : maxval;
    }
    for(int exp = 1; maxval/exp > 0; exp *= 10)
    {
    	radix_countsort(dsize, arr, exp);
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


	radixsort(dsize, arr);    



    for(int i=0;i <= 10;++i)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;

}
int main()
{
    int arr1[]={6,5,7,1,3,6,0,8,4,2,5};
    int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
    int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
    int arr4[]={1,1,1,1,102,1,100,1,1,1,1};
    sort(arr1);
    sort(arr2);
    sort(arr3);
    sort(arr4);
    return 0;
}
