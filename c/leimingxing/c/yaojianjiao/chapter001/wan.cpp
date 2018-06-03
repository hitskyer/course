#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main(){
	char p ;
	int a, b;
	do{
		cout<<">>您好！这是一个万能计算器，欢迎使用. 您想使用的是加减乘除哪个运算方法呢？<<"<<endl;
		printf("请输入您要运算的方法\n 加(+)减(-)乘(*)除(/)\n");
		cin>>p;
		while(true){
			if('+'==p){
				cout<<"请输入要操作的两个数字！"<<endl;
				cin>>a>>b;
				cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为:"<<a+b<<endl;
				break;
			}else if('-'==p){
				cout<<"请输入要操作的两个数字！"<<endl;
				cin>>a>>b;
				cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为:"<<a-b<<endl;
				break;
			}else if('*'==p){
				cout<<"请输入要操作的两个数字！"<<endl;
				cin>>a>>b;
				cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为:"<<a*b<<endl;
				break;
			}else if('/'==p){
				cout<<"请输入要操作的两个数字！"<<endl;
				cin>>a>>b;
				cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为:"<<a/b<<endl;
				break;
			}else{
				cout<<"您输入的有误，请重新输入:\n加(+)减(-)乘(*)除(/)"<<endl;
				cin>>p;
				continue;
			}
		}
		cout<<"是否继续y/n:"<<endl;
		cin>>p;
	}while('Y'==p||'y'==p);
	
	cout<<"欢迎再次使用！"<<endl;
	
	return 0;
}
