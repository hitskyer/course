#include<stdio.h>
#include<iostream>

using namespace std;

int main(int argc,char* args[]){
	cout<<" 你好欢迎测试使用除法计算器\n 请您输入两个数字 "<< endl;
	int a=0 ;
	int b=0;
	cin >> a;
	cin >> b;//增加注释；接收输入的数字
	cout<<"您好，您输入的为："<<a<<"和"<<b<<",计算结果为："<<a/b <<endl;
	return 0;
}
