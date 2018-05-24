#include <iostream>
#include <stdio.h>
using namespace std;

int Add(int a,int b)
{
	return a+b;
}
int Sub(int a,int b)
{
	return a-b;
}
int Mult(int a,int b)
{
	return a*b;
}
int divi(int a,int b)
{
	return a/b;
}
typedef int (*OPTYPE)(int a,int b);
OPTYPE pFun;

void DecisionSymbol(int &a,char &c,int &b)
{
	int k=0;
	switch(c)
	{
	case '+':
		pFun=Add;
		k=(*pFun)(a,b);
		break;
	case '-':
		pFun=Sub;
		k=(*pFun)(a,b);
		break;
	case '*':
		pFun=Mult;
		k=(*pFun)(a,b);
		break;
	case '/':
		pFun=divi;
		if(!b)
		{
			cout<<"分母不能为零！"<<endl;
			return ;
		}
		k=(*pFun)(a,b);
		break;
		
	}
	cout<<a<<c<<b<<'='<<k<<endl;
}

int main(int argc, char* argv[])
{
	int k=0,a=0,b=0;
	char c=0;
	char c1=0;
	int i=0;	
	do
	{	
		if (!i)
		{
			cout<<"请输入两个整数和运算符【如1+2】:"<<endl;
			i=1;
		}
		else
			cout<<"请您继续输入："<<endl;
		cin>>a>>c>>b;
		DecisionSymbol(a,c,b);
		cout<<"请问是否继续计算【按N或n退出，按任意键继续计算】:"<<endl;
		cin>>c1;
        }while(c1!='N'&& c1!='n');
	return 0;
	}
	
