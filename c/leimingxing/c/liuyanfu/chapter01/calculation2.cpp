#include <iostream>
using namespace std;

float Add(float a,float b)
{
	return a+b;
}
float Sub(float a,float b)
{
	return a-b;
}

float Mult(float a,float b)
{
	return a*b;
}

float divi(float a,float b)
{
	return a/b;
}

typedef float(*OPTYPE)(float a,float b);
OPTYPE pFun;

void DecisionSymbol(float &a,float &b,char &c)
{
	float k=0;
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
void CheckInput(float &a,float &b,char &c)
{
	
	while(!(cin>>a>>c>>b))
	{
		cout<<"您输入的不正确，请重新输入："<<endl;
		cin.clear();
		cin.ignore(100,'\n');		
	}
	
}
int main(int argc, char* argv[])
{
	float k=0,a=0,b=0;
	char c=0;
	char c1=0;
	int i=0;	
	do
	{	
		if (!i)
		{
			cout<<"请输入两个数字和运算符【如1+2】:"<<endl;
			i=1;
		}
		else
			cout<<"请您继续输入："<<endl;
		CheckInput(a,b,c);
		DecisionSymbol(a,b,c);
		cout<<"请问是否继续计算【按N或n退出，按任意键继续计算】:"<<endl;
		cin>>c1;
	}while(c1!='N'&& c1!='n');


	return 0;
	
}

