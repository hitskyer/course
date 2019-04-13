/**
 * @description: 寻找第K大的元素
 * @author: michael ming
 * @date: 2019/4/13 13:02
 * @modified by: 
 */
#include <iostream>
#include <time.h>
#include <random>
#include "shellsort.cpp"
using namespace std;
void printArr(int* arr, size_t N)
{
    for(int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void generateArr(int* arr, size_t N)
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < N; ++i)
        arr[i] = rand()%100;
}
void selectMiddle(int *arr, size_t left, size_t right)
{
    size_t mid = left + (left + right)/2;
    if(arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    if(arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if(arr[mid], arr[left])
        swap(arr[mid], arr[left]);
}
int findkthelem(int *arr, size_t N, size_t K, size_t left, size_t right)
{
    selectMiddle(arr, left, right);
    int Pval = arr[left];
    size_t Pindex = left, i = left, j = right;
    while(i < j)
    {
        while(i < j && arr[i] <= Pval)
            i++;
        swap(arr[i],arr[j]);
        while(i < j && arr[j] > Pval)
            j--;
        swap(arr[i],arr[j]);
    }
    Pindex = i;
    if(i+1 == K)
        return arr[i];
    else if(i+1 < K)
        return findkthelem(arr, right-Pindex, K, Pindex+1,right);
    else
        return findkthelem(arr, Pindex-left, K, left, Pindex-1);
}
int main()
{
    size_t N, K;
    cout << "请输入正整数N：程序将生成随机数组。" ;
    cin >> N;
    int arr[N];
    generateArr(arr, N);
    printArr(arr, N);
    cout << "请输入K：程序将查找第K大的元素。";
    while(true)
    {
        cin >> K;
        if(K > 0 && K <= N)
            break;
        cout << "K超过N了，或者为0" << endl;
        continue;
    }
    shellsort(arr, N);
    cout << "排序后数组是：" << endl;
    printArr(arr, N);
    cout << "第" << K << "大的元素是：" << findkthelem(arr,N,K,0,N-1) << endl;
    return 0;
}