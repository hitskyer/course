#include <stack>
#include <iostream>
#define N 1001
using namespace std;
int main()
{
    int Barr[N], i = 0, j = 0, len;
    while(cin >> len && len)    //输入火车长度
    {
        while (1)
        {
            stack<int> station;
            for(i = 0; i < len; ++i)    //输入火车B站的车厢顺序
            {
                cin >> Barr[i]; 
                if(Barr[0] == 0)    //第一个车厢是0，结束
                    break;
            }
            if(Barr[0] == 0)    //第一个车厢是0，结束
            {
                break;
            }
            for(i = 1, j = 0; i <= len; ++i)    //对1-N的车厢进行操作
            {
                while(!station.empty() && station.top() == Barr[j]) //中转站（栈）不为空则，比较栈顶与B的车厢的号码
                {
                    station.pop();  //相等的话，车厢出栈
                    j++;    //可以比较下一个车厢号码了
                }
                station.push(i);    //栈为空或者栈顶车厢号与要求的不等，则直接把A站的车压入栈内
            }
            while(!station.empty() && station.top() == Barr[j]) //当1-N都压栈完了，栈内还有车厢的话，顺次和栈顶比较
            {
                station.pop();
                j++;
            }
            if(station.empty()) //最后栈内为空则，可以匹配要求的顺序
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}	//test push from github desktop