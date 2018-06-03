#include <iostream>
#include <string>
int main()
{
	using namespace std;
	double x=0,y=0;
	string s;	//定义继续计算字符
	do
	{
		cout << "------------------\n请输入两个数，求商！" << endl;
		while(true)
		{
			if(!(cin>>x>>y))	
				{
				cout << "检测到非数字，请重新输入！"<< endl;
        	               	cin.clear();
                	       	cin.ignore(1000,'\n');
				}
			else if(y==0)
				{
				cout << "请输入非0的除数！！！" << endl;
                        	cin.clear();
                        	cin.ignore(1000,'\n');
				}
			else
				{
				cout << x << " and " << y << "的商为：" << x/y << endl;
				break;
				}
		}
		cout << "请输入y或者Y继续计算，输入其他字符结束计算！"<< endl;
		cin >> s;
	}
	while(s == "y" || s == "Y");
	return 0;
}
