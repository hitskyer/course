#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int arr[5]={1,6,7,4,10};
    int arr1[4] = {10,1,4,8};
    int val = 10;
    int int_count = count_if(arr,arr+5,bind2nd(less_equal<int>(),val));// X <= 10
    cout << int_count << endl;
    int_count = count_if(arr,arr+5,bind1st(less_equal<int>(),10));// 10 <= X
    cout << int_count << endl;
    int_count = count_if(arr,arr+5,not1(bind2nd(less_equal<int>(),10)));// !(X <= 10)
    cout << int_count << endl;
    int *find_int = find_first_of(arr,arr+5,arr1,arr1+4,not2(less_equal<int>()));// 二元操作取反
    cout << *find_int << endl;
    cout << find_int << " " << arr << endl;
    return 0;
}

