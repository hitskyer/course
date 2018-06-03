#include<iostream> //引用输入输出流库
using namespace std;//定义全局命名空间
int main()
{
	cout << "Enter 2 numbers:" << endl;//输入并且刷新缓冲区。

	int a = 0,b = 0;//定义两个整数变量。
	cin  >> a >> b;
	cout << "The multi of " << a << " and "<< b
             << " is " << a * b << endl;//计算并且输出。
	return 0;
}
