#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
        //显示提示信息
        cout << "Enter two number!" << endl;
        //定义变量并初始化               
        int a=0,b=0;
	//接受用户的输入信息
       /**/
	cin >> a >> b;
/*	while (!scanf("%d",&a)) {
	 fflush(stdin);
	printf("usage :%s 输入错误,请重新输入\n");
	cin >>a;
	}
	 while (!scanf("%d",&b)) {
         fflush(stdin);
        printf("usage :%s 输入错误,请重新输入\n");
       	cin >> b;
	 }
*/
	//打印信息
	cout << a << "-" << b << "is" << a-b<< endl;
	
      return  0;
}
        
        
        
        
        
                                     
