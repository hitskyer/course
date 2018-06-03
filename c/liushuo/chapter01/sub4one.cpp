#include<iostream> //引用输入输出流库
#include <string>
int main()
{
        using namespace std;//定义全局命名空间
	double x=0 ,y=0;//定义两个浮点型变量。
	string s;//定义程序“是否继续”字符s
	do
	{
        cout <<" ----------------------\nEnter 2 numbers: \n";//输入并且刷新缓冲区。
		while(!(cin>>x>>y))//判断是否都为数字
		{
		cout << "输入了非数字，请输入两个数字！！！"<< endl;
		cin.clear();//让错误的标示改回为0，让我们可以继续输入。
		cin.ignore(1024,'\n');
		}
	cout << "The sub of " << x << " and "<< x
             << " is " << double(x-y) << '\n';//计算并且输出。
	cout << "Enter y or Y to continue the calculation:\nEnter other character to quit:"<<endl;
	cin >> s;
	}
	while(s == "y" || s == "Y");
	return 0;
}
}
