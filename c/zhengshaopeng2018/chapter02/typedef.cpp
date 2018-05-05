#include<iostream>
#include<string>
using namespace std;
int main()
{
	typedef int length;//int的同义词为长度
	typedef int high;//int的同义词为高度
	typedef int width;//int的同义词为宽度
	length a ;
	width b ;
	high c ;
	cout<<"输入一个长方体的长宽高 : "<<endl;
	cin>>a>>b>>c;
	cout<<"长方形的体积为 : "<<a*b*c<<endl;
	return 0;
}
