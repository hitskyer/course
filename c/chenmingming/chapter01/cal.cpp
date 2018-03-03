#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "请输入你想要做的计算：\n";
	cout << "1.加法\n";
	cout << "2.减法\n";
	cout << "3.乘法\n";
	cout << "4.除法\n";
	cout << "5.退出计算器"<< endl;
	double x=0,y=0;
	int i=0;
	char s;
	while(true)
	{
		if(!(cin >> i ))
		{
			cin.clear();
			cin.ignore(1000,'\n');
	        	cout << "请输入以下计算前的序号数字：\n";
	        	cout << "1.加法\n";
	       		cout << "2.减法\n";
	        	cout << "3.乘法\n";
	        	cout << "4.除法\n";
	        	cout << "5.退出计算器"<< endl;
			continue;
		}
		while(true)
		{
			cin.ignore(1000,'\n');
			if(i==1)		//加法
			{
				do
				{
				cout << "输入两个数做加法:" << endl;
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
				cout << "请输入y或者Y继续，输入其他字符结束加法计算！"<< endl;
				s=cin.get();
				cin.ignore(1000,'\n');
				}
				while(s == 'y' || s == 'Y');
				break;
			}
        	        else if(i==2)	//减法
	                {
			        do
			        {
			        cout << "-------------------------------\n请输入两个数做减法！\n";
			                while(!(cin >> x >>y))  //判断是否都为数字
                			{
	                	        cout << "输入了非数字，请输入两个数字！！！" << endl;
                	        	cin.clear();            //让错误标识改回为0,让我们可以继续输入
		                        cin.ignore(1000,'\n');  //清空已输入的数据
                       			}
			        cout << x<< " 和 "<< y<< "两数之差为：" << double(x-y) << "\n";
			        cout << "输入y或者Y继续！\n输入其他任意字符退出减法！" << endl;
			        cin.ignore(1000,'\n');  //清空2个数，后面多余的输入（比如输入3个数字）
			        s=cin.get();
			        cin.ignore(1000,'\n');  //清空已输入的数据(比如一长串字符，无效的，多余的
			        }
			        while(s == 'y' || s == 'Y');    //输入y或Y继续执行程序
				break;
	                }
	                else if(i==3)	//乘法
	                {
				do
			        {
		                cout << "------------------\n请输入两个数，求乘积！\n";
                			while(!(cin >> x >>y))
                			{
		                        cout << "输入了非数字，请输入数字！\n";
                		        cin.clear();
		                        cin.ignore(1000,'\n');
                			}
		                cout << x << " and " << y << "的乘积为：" << x*y << "\n";
                		cout << "请输入y或者Y继续，输入其他字符结束乘法！"<< endl;
		                cin.ignore(1000,'\n');
                		s=cin.get();
		                cin.ignore(1000,'\n');
        			}
			        while(s == 'y' || s == 'Y');
	                	break;    
	                }
	                else if(i==4)	//除法
	                {
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
                                		cin.ignore(1000,'\n');
		                                cout << x << " and " << y << "的商为：" << x/y << endl;
                		                break;
                                		}
                			}
			                cout << "请输入y或者Y继续，输入其他字符结束除法！"<< endl;
			                s=cin.get();
			                cin.ignore(1000,'\n');
        			}
			        while(s == 'y' || s == 'Y');
		                break;    
	                }
			else
			{
                        	break;
			}
		}
		cout << "返回计算器请输入y或Y，输入其他字符退出计算器！" << endl;
                s = cin.get();
                cin.ignore(1000,'\n');
	                if(s == 'y'|| s == 'Y')
                                {
                                cout << "请输入以下计算前的序号数字：\n";
                                cout << "1.加法\n";
                                cout << "2.减法\n";
                                cout << "3.乘法\n";
                                cout << "4.除法\n";
                                cout << "5.退出计算器"<< endl;
                                continue;
                                }
                        else
                        break;
	}
}
