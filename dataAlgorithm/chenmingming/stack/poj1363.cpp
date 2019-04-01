// http://poj.org/problem?id=1363
// Created by mingm on 2019/4/1.
//
#include <stack>
#include <iostream>
#define N 1001
using namespace std;
int main()
{
    int Barr[N], i = 0, j = 0, len;
    while(cin >> len && len)
    {
        while (1)
        {
            stack<int> station;
            for(i = 0; i < len; ++i)
            {
                cin >> Barr[i];
                if(Barr[0] == 0)
                    break;
            }
            if(Barr[0] == 0)
            {
                cout << endl;
                break;
            }
            for(i = 1, j = 0; i <= len; ++i)
            {
                if(i == Barr[j])
                {
                    j++;
                    continue;
                }
                else
                {
                    if(!station.empty() && station.top() == Barr[j])
                    {
                        station.pop();
                        j++;
                        continue;
                    }
                    else
                    {
                        station.push(i);
                    }
                }
            }
            while(!station.empty() && station.top() == Barr[j++])
                station.pop();
            if(station.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
