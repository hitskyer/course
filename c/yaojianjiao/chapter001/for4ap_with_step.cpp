#include<iostream>

using namespace std;


int main(){

//实现带步长的等差数列求和for4ap_with_step.cpp
//1+2+3+4+5  步长2 1-5加和= 1+3+5

int step=1,sum=0,start=1,end=0;
cout<<"您好，请输入要计算的加和范围"<<endl;
cin>>end;//加到几为止
cout<<"请您输入计算数值时候的步长为多少？ "<<endl;
cin>>step;//步长值

//开始循环计算结果
for(start;start<=end;(start=start+step)){
	// 步长为2   计算1-5  的结果为 1+3+5
	// 步长为3   计算1-10 的结果为1+4+7+10
	
	sum=sum+start;
	cout<<"start: "<<start<<endl;
//	start=start+step;
}
cout<<"结算结果为"<<sum<<endl;

return 0;
}
