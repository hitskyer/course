#include<iostream> //引用输入输出流库
using namespace std;//定义全局命名空间
int main()
{
	cout << "Enter 2 numbers:" << endl;//输入并且刷新缓冲区。

	int a = 0,b = 0;//定义两个整数变量。
	cin  >> a >> b;
        if (b !=0)//判断被除数是否为零
	{
	cout << "The div of " << a << " and "<< b
             << " is " << a / b << endl;//计算并且输出。
        cout <<"The remainder of " << a << " and "<< b
             << " is " << a % b << endl;//计算余数并输出。
	}
	else
	{
	cout << "Nice try, but the dividend cannot be 0."<<endl;
	}
	return 0;
}
