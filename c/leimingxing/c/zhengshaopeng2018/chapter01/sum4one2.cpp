#include<iostream>
using namespace std;

int main()
{
        //endl表示立即刷新缓冲区，并输出换行，便于定位问题且美观
        cout << " Enter two numbers "<< endl;
        //初始化所需变量，定义的同时初始化是非常好的习惯
        int a = 0 ;
        int b = 0 ;
        //程序会在这里等待两个整数的输入
        cin >> a;
        cin >> b;
        //拿到数据后，会计算并输出
        cout << " The sum of " << endl ;
        cout << a << endl ;
        cout << " and " << endl;
        cout << b << endl;
        cout << " is " << endl;
        cout << a+b << endl;
        
        //报告老大，我把活正常干完了
        return 0;
}
