#include<iostream>
using namespace std;


void adjust(int *arr, size_t i, size_t dsize)
{
    size_t LowerLeftNode = i*2+1;   //下一层左边的节点
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
    for(size_t i = dsize/2 -1; i >=0;--i)   //底下第二层
    {
        adjust(arr,i,dsize);
        if(i == 0)
        {
            break;
        }
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
        {
            break;
        }
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



//    size_t left = 0, right = dsize-1;
    heapsort(dsize,arr);


    for(int i=0;i <= 10;++i)
    {
        cout << arr[i]<< " ";
    }
    cout << endl;

}
int main()
{
    int arr1[]={6,5,7,1,3,6,6,8,4,2,5};
    int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
    int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
    int arr4[]={2,1,1,1,1,1,1,1,1,1,1};
    sort(arr1);
    sort(arr2);
    sort(arr3);
    sort(arr4);
    return 0;
}
