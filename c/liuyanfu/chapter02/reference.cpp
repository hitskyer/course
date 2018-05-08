#include<iostream>
using namespace std;

int main()
{
	//可以有引用的引用，
	//同一个值可以有多个引用
	int i_1=1000;
	int &i_2=i_1;
	int &i_4=i_1;
	int &i_3=i_2;
	//给引用赋值，是非法的
	//int i_4=500;
	cout<<i_1<<","<<i_2<<","<<i_3<<","<<i_4<<endl;
	cin>>i_1;
	cout<<i_1<<","<<i_2<<","<<i_3<<","<<i_4<<endl;
	const int &c_i=i_1+1;
	const int &c_j=502;
	cout<<c_i<<endl;
	cout<<c_j<<endl;
	int j_1=200,j_2=300;
	j_1=j_2;
	j_2=j_1;
	cout<<j_1<<","<<j_2<<endl;
	int a,&b=a;
	a=5,b=10;
	cout<<a<<","<<b<<endl;
	return 0;

}
