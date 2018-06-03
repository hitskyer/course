#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char * p=(char*) malloc(100);
	int a, b,c;//a输入值1，b输入值2，c计算输入的a和b返回的结果
	char flag ;//输入是否继续的标记
	//do{} while()
	do{
		cout<<">>您好！这是一个万能计算器，欢迎使用. 您想使用的是加减乘除哪个运算方法呢？<<"<<endl;
		printf("请输入您要运算的方法\n 加(+/add/plus)减(-/sub)乘(*/mulit)除(/div)\n");
		cin>>p;
		while(true)
	//	if((0==strcmp(p,"add")) || ("+"==p)){  // 不知道为什么 “+”==p不行？？？
		if((0==strcmp(p,"add")) || (0==strcmp(p,"+")) || (0==strcmp(p,"plus")) ){
			cout<<"请输入要操作的两个数字！"<<endl;
			cin>>a>>b;
			c=a+b;
			cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为:"<<c<<endl;
			break;
		}else if(0==strcmp(p,"sub")||0==strcmp(p,"-")){
			cout<<"请输入要操作的两个数字！"<<endl;
			cin>>a>>b;
			c=a-b;
			cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为"<<c<<endl;
			break;
		}else if(0==strcmp(p,"mulit")||0==strcmp(p,"*")){
			cout<<"请输入要操作的两个数字！"<<endl;
			cin>>a>>b;
			c=a*b;
			cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为"<<c<<endl;
			break;
		}else if(0==strcmp(p,"div")||0==strcmp(p,"/")){
			cout<<"请输入要操作的两个数字！"<<endl;
			cin>>a>>b;
			c=a/b;
			cout<<"您输入的为"<<a<<"和"<<b<<"计算结果为"<<c<<endl;
			break;
		}else{
			cout<<"输入有误，请重新输入\n加(+/add/plus)减(-/sub)乘(*/mulit)除(/div)"<<endl;
			cin>>p;
			continue;
		}
		cout<<"是否继续 (Y/N)?"<<endl;
		cin>>flag;
	}while('Y'==flag||'y'==flag);
		
	cout<<"good bye !!!"<<endl;

	return 0;
}





