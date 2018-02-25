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
	int x=0,y=0;
	char s;
	do
	{
		cout << "Enter two numbers:" << endl;
		while(true)
		{
			if(!(cin >> x >> y))
			{
			cout << "检测到非数字，请重新输入！"<< endl;
       	               	cin.clear();
               	       	cin.ignore(1000,'\n');
			}
			else
			{
			cin.ignore(1000,'\n');
			cout << x << " and " << y << "的和为：" << x+y << endl;
			break;
			}
		}
		cout << "请输入y或者Y继续计算，输入其他字符结束计算！"<< endl;
		s=cin.get();
		cin.ignore(1000,'\n');
	}
	while(s == 'y' || s == 'Y');
	return 0;	
}
