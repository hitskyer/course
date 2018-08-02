#include<iostream>
using namespace std;


void partion2(int *arr, size_t left, size_t right, size_t &lessPnum, size_t &largePnum)//数据分段
{
    int pval = arr[left];  //左边的数赋值给哨兵
    int *temp = new int [right-left+1]();  //开辟堆空间存放临时数组
    int tempLindex=0, tempRindex = right-left;  //临时数组的首末位下标
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i]) //比哨兵小的放在左边，从左边首位往中间写入，记录下比哨兵小的有多少个
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        else  //比哨兵大或等于的放在右边，从右边末位往中间写入，记录下比哨兵大和等的有多少个
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    temp[tempLindex] = pval;
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++]; //把分好段的数组写回原数组{[小于哨兵的],[大于等于哨兵的]}
    }
    delete [] temp; //释放临时数组
    temp = NULL;  //指针置空
}
void qsort2(int *arr, size_t left, size_t right, int deep)
{
    if(left >= right)
    {
        return;
    }
    else
    {
        size_t lessPnum = 0, largePnum=0;
        partion2(arr,left,right,lessPnum,largePnum);  //数据分段，{[小于哨兵],[等于哨兵],[大于哨兵]}
        size_t p_index = left + lessPnum;  //哨兵的下标
        if(p_index == right)  //哨兵位于数组最右边，且左边还有数据
        {
            qsort2(arr,left,p_index-1,deep); //只对左边非哨兵数据快排
        }
        else if(p_index == left)  //哨兵位于数组最左边，且右边还有数据
        {
            qsort2(arr,p_index+1,right,deep);  //只对右边非哨兵数据快排
        }
        else  //两侧都有非哨兵数据，对两侧调用快排
        {
            qsort2(arr,left,p_index-1,deep);
            qsort2(arr,p_index+1,right,deep);
        }
    }
}
void quicksort2(size_t dsize, int *arr)
{
    if(dsize <= 1)  //预防特殊情况下后面代码失效
    {
        return;
    }
    size_t left = 0, right = dsize-1;
    int deep = 0;  //可以打印显示出调用的层数
    qsort2(arr,left,right,deep);
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
    quicksort2(dsize,arr);


    for(int i=0;i <= 10;++i)
    {
        cout << arr[i] << " ";
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
