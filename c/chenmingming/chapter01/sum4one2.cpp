#include <iostream>
using namespace std;

/*
 * 1. 课程范围："c++ primer"第4版第1.2.2节
 * 2. 课后练习：
 *    a) 读懂注释：向别人讲述自己的理解
 *    b) 编译程序：g++ sum4one.cpp -o sum4one
 *    c) 正常执行（输入两个整数）
 *    d) 非法执行（输入两个字符串）
 *    e) 思考问题：我如何保证程序始终处于正确状态，而不受非法输入的干扰？
 */
int main()
{
	/* 程序开始
	 * 提示输入
	 * 等价表达式：(std::cout << "Enter two numbers:") << std::endl;
	 * endl是立即刷新缓冲区，并输出换行，便于定位问题且美观
	*/
	cout << "Enter two numbers:" << endl;

	// 初始化所需变量，定义的同时初始化是非常好的习惯
	int a = 0, b = 0;
	// 程序会在这里等待两个整数的输入
	// cin >> a;
	// cin >> b;
	cin >> a >> b;
	// 拿到输入后，会计算并输出
	cout << "The sum of " << a << " and " << b
		<< " is " << a+b << endl;
	
	// 报告老板，我把活正常干完了
	return 0;
}
