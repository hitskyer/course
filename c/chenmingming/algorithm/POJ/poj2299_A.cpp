#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    const int N = 500000;
    int len,len1,sum=0;
    long int arr[N];
    int j=0,k=0,temp;
    memset(arr,0,sizeof(long int)*N);
    while(cin >> len && len != 0)
    {
        //cin.clear();
        len1=len;
        j=0;
        while(len1--)	//先输入数组
        {
            cin >> temp;
            arr[j++] = temp;
        }
        for(j = 0; j < len; ++j)	//从前往后依次比较
        {
            for(k = j+1; k < len; ++k)
            {
                if(arr[j]>arr[k])
                {
                    sum++;
                }
            }
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}