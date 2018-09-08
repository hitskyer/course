#include<iostream>
using namespace std;
int main()
{
    char alpha;
    int quicksum = 0;
    while(cin.get(alpha) )
    {
        if(alpha == '#')
            break;
        quicksum = 0;
        for(int i = 1; alpha != '\n';++i)
        {
            if(alpha != ' ')
                quicksum = quicksum + i*(alpha-'A'+1);
            cin.get(alpha);//cin.get()可以捕捉空格, cin >> char 不可以捕捉空格回车
        }
        cout << quicksum << endl;
    }
}