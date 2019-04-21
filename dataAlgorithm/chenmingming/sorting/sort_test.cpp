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
#include "quicksort.cpp"
#include "heapsort.cpp"
#include "countsort.cpp"
#include "bucketsort.cpp"
#include "radixsort.cpp"
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
    clock_t start, finish;
    srand(time(NULL));
    const size_t N = 10000;
    int originArr[N];
    generateArr(originArr, N);
    printArr(originArr, N);
    cout << "-------------------------" << endl;
    cout << "after bubble sorting :" << endl;
    start = clock();
    bubblesort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after insert sorting :" << endl;
    start = clock();
    insertsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after select sorting :" << endl;
    start = clock();
    selectsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after shell sorting :" << endl;
    start = clock();
    shellsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after merge sorting :" << endl;
    start = clock();
    mergesort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after quick sorting :" << endl;
    start = clock();
    quicksort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after heap sorting :" << endl;
    start = clock();
    heapsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after count sorting :" << endl;
    start = clock();
    countsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after bucket sorting :" << endl;
    start = clock();
    bucketsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    cout << "-------------------------" << endl;
    cout << "after radix sorting :" << endl;
    start = clock();
    radixsort(originArr, N);
    finish = clock();
    printArr(originArr, N);
    cout << "takes "<< finish-start << " ms." << endl;
    return 0;
}