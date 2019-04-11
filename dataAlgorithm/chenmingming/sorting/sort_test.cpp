/**
 * @description: 排序测试主程序
 * @author: michael ming
 * @date: 2019/4/8 19:56
 * @modified by: 
 */
#include <iostream>
#include <time.h>
#include <random>
#include "bubble_sort.cpp"
#include "insert_sort.cpp"
#include "select_sort.cpp"
#include "shellsort.cpp"
#include "mergesort.cpp"
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
    for(int i = 0; i < N; ++i)
        arr[i] = rand()%100;
}
int main(int argc, char* argv[])
{
    srand(time(NULL));
    const size_t N = 15;
    int originArr[N];
    generateArr(originArr, N);
    printArr(originArr, N);
//    cout << "after bubble sorting :" << endl;
//    bubblesort(originArr, N);
//    printArr(originArr, N);
//    cout << "after insert sorting :" << endl;
//    insertsort(originArr, N);
//    printArr(originArr, N);
//    cout << "after select sorting :" << endl;
//    selectsort(originArr, N);
//    printArr(originArr, N);
//    cout << "after shell sorting :" << endl;
//    shellsort(originArr, N);
//    printArr(originArr, N);
    cout << "after merge sorting :" << endl;
    mergesort(originArr, N);
    printArr(originArr, N);
    return 0;
}