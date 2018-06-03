
#include<iostream>
using namespace std;
int main()
{
	cout<<"'a'  "<<'a'<<endl;
	cout<<"L'a'  "<<L'a'<<endl;
	cout<<"a字符  "<<"a"<<endl;
	cout<<"L a字符 "<<L"a"<<endl;

	cout<<10<<"  "<<sizeof(10)<<endl;
	cout<<10u<<"  "<<sizeof(10u)<<endl;
	cout<<10L<<"  "<<sizeof(10L)<<endl;
	cout<<10uL<<"  "<<sizeof(10uL)<<endl;
	cout<<012<<"  "<<sizeof(012)<<endl;
	cout<<0xC<<"  "<<sizeof(0xC)<<endl;

	cout<<3.14<<"  "<<sizeof(3.14)<<endl;
	cout<<31.4f<<"  "<<sizeof(3.14f)<<endl;
	cout<<3.14L<<"  "<<sizeof(3.14L)<<endl;
	
	cout<<10<<"  "<<sizeof(10)<<endl;
	cout<<10u<<"  "<<sizeof(10u)<<endl;
	cout<<10.<<"  "<<sizeof(10.)<<endl;
	cout<<10e-2<<"  "<<sizeof(10e-2)<<endl;
	return 0;
}
