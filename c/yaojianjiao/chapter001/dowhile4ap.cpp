#include<iostream>

using namespace std;

int main(){

int a=0,sum=0,c=1;
char flag='y';
do{
	cout<<"请输入要计算的数据范围（您要操作的是从1开始计算到加多少为止即 1+2+3+....）"<<endl;
	cin>>a;
	for(c;c<=a;c++){
		sum=sum+c;
	}	
/**
	while(c<=a){//循环条件
	 	sum=sum+c; //等价于sum+=c ; //进行数据加和操作
		c++;//c=c+1
	}
**/
	cout<<"您计算的结果为"<<sum<<endl;
	cout<<"是否继续（y/n）"<<endl;
	cin>>flag;
}while(flag=='y');

cout<<"good bye !!!"<<endl;

return 0;
}
