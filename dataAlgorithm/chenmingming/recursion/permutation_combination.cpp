/**
 * @description: 给一组数据，求排列组合
 * @author: michael ming
 * @date: 2019/4/8 22:29
 * @modified by: 
 */
#include <iostream>
using namespace std;
void permutation_comb(int *arr, size_t n, size_t i)
{
    if(i == n-1)
    {
        for(int i=0; i<n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for(int j=i; j<n; ++j)
        {
            swap(arr[i],arr[j]);
            permutation_comb(arr,n,i+1);
            swap(arr[i],arr[j]);
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4};
    permutation_comb(arr,4,0);
    return 0;
}