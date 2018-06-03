#include<iostream>
using namespace std;

int main()
{
         //endl表示立即刷新缓冲区并输出换行，便于定位问题且美观
         cout << " Enter two numbers: " << endl;
         //初始化所需要的变量，定义的同时初始化是非常好的习惯
         int a = 0, b = 0;
         //程序会在这里等待两个整数的输入
         //cin >> a;
         //cin >> b;
         cin >> a >> b;
         //拿到输入后，会计算并输出
         cout << " The sum of " << a << " and " << b
              << " is " << a/b << endl;
         //报告BOSS，我已经把活干完了
         return 0;
}
