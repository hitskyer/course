#include<iostream>
using namespace std;

int main()
{
        //endl 是立即刷新缓冲区，并且输出换行，便于定位问题且美观
        cout << "Enter two numbers:" << endl;
        
        //初始化所需变量，定义的同时初始化是很好的习惯
        int a = 0, b = 0;
        //程序会在这里等待两个整数的输入
        cin >> a >> b;
        //拿到输入后，会计算输出
        cout << "The sum of " << a << " and " << b 
             << " is " << a-b << endl;
        return 0;
}

