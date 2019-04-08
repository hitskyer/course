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
    cout << endl;
    cout << "after sorting :" << endl;
    bubblesort(originArr, N);
    printArr(originArr, N);
    return 0;
}