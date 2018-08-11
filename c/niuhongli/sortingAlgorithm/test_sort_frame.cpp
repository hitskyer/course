#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include <string.h>


void  bubSort(size_t dsize,int *array)
{
        for(size_t i=1;i<dsize;++i){
                for (size_t j=0;j<=dsize-1-i;++j){
                        if(array[j]>array[j+1])
                                swap(array[j],array[j+1]);//交换
                }
        }
}

void sort(int *arr)
{
    int dsize = 11;
    for(int i=0;i < dsize;++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
	bubSort(dsize, arr);    

    for(int i=0;i <dsize;++i)
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
