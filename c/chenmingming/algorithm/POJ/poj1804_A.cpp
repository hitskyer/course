#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    const int N = 1001;
    int cyctime,len,len1,sum=0;
    int arr[N];
    int i=0,j=0,k=0,temp;
    memset(arr,0,sizeof(int)*N);
    cin >> cyctime;
    for(i = 0; i < cyctime; ++i)
    {
        //cin.clear();
        cin >> len;
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
        cout << "Scenario #" << i+1 << ":" << endl;
        cout << sum << endl << endl;
        sum = 0;
    }
    return 0;
}