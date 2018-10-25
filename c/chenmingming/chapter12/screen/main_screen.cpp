#include"screen.h"
#include<iostream>
using namespace std;
int main()
{
	Screen myscreen(5,6,"aaaaa\naaaaa\naaaaa\naaaaa\naaaaa\n");
	//定义Screen类对象myscreen，初始化为5行6列的字符
	myscreen.move(4,0).set('#').display(cout);
	//move使光标移动到指定的第5行，第1列，返回的是对象自己*this
	//set使光标处字符变成#
	//display用cout输出所有字符
	cout << "光标当前所在位置和字符为： " << myscreen.get_cursor() << " " << myscreen.get() << endl;
	string::size_type r=1, c=1;
	cout << "输入你要获取的位置行列数字（从1开始）：" << endl;
	cin >> r >> c;
	cout << myscreen.get(r,c) << endl;
	return 0;
}