#include<iostream>
using namespace std;
int main()
{
    float len = 0,sum;
    int n;
    while(cin >> len && len != 0)
    {
        for(n=2,sum=0;sum<len;++n)
        {
            sum += 1/(n*1.0);
        }
        cout << n-2 << " " << "card(s)" << endl;
    }
}