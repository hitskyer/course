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
                break;
            }
            for(i = 1, j = 0; i <= len; ++i)
            {
                while(!station.empty() && station.top() == Barr[j])
                {
                    station.pop();
                    j++;
                }
                station.push(i);
            }
            while(!station.empty() && station.top() == Barr[j])
            {
                station.pop();
                j++;
            }
            if(station.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}	//test push from github desktop