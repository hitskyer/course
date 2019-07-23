/**
 * @description: dp,poj1276,atm给钱问题
 * @author: michael ming
 * @date: 2019/7/22 21:46
 * @modified by: 
 */
#include <iostream>
#include <memory.h>

using namespace std;
int *states = new int [100001];
//int states[13];
int exchange(int targetMoney, int *amount, int *rmb, int kinds)
{
    if(targetMoney == 0)
        return 0;
    memset(states,0,100001*sizeof(int));
    int i,j,k;
    for(i = 0; i < kinds; ++i)
        for(k = 0; k < amount[i]; ++k)
            for(j = targetMoney; j >= rmb[i]; --j)
            {
                states[j] = max(states[j],states[j-rmb[i]]+rmb[i]);
//                cout << j << " " << states[j] << endl;
            }
    return states[targetMoney];
}
int main()
{
    int targetMoney, k, rmb[10], amount[10];
    while(cin >> targetMoney >> k)
//    cin >> targetMoney >> k;
    {
        if(k == 0)
            cout << "0" << endl;
        else
        {
            for(int i = 0; i < k; ++i)
            {
                cin >> amount[i] >> rmb[i];
            }
            cout << exchange(targetMoney,amount,rmb,k) << endl;
        }
    }
    delete [] states;
    return 0;
}