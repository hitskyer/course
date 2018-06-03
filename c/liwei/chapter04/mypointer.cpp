#include<iostream>

#include<string>

using namespace std;

int main()

{
int *pi=0;// pi initialized to adress no object

	

	int ival=12;

	int *pi1= &ival; //pi initilized to the adress of -int type object ival;

	int *pi2=pi1;

	int *pi3=NULL; // INT *PI=0;
// 获取指针所指向的对象

 	string s("My best friend");

 		string *sp=&s;

 			cout << *sp;

 				*sp="My worst friend";

 					cout << s << endl;
//

 	int ival1=100, ival2=200;

 		int *pi4=&ival1, *pi5=&ival2;

 			cout << *pi4 << endl;

 				cout << *pi5 << endl;

					pi4=pi5;

 						cout << *pi4 << endl;

// //指针访问数组元素

 	int ia[]={0,1,2,3,4};

 		int *ip=ia;

 			cout << *ip;

 				int *ip1 =&ia[4];

					cout << *ip1;

 						int *ip2;

 							ip2=ia;

	int *ip3=ip2+4;

 	int *ip3;

 		ip3=ip2+2;

 			cout << *ip3 << endl;
//指针输出数组元素

 	const size_t arr_sz=5;

 		int int_arr[arr_sz]={0,1,2,3,4};

 			for (int *pbegin=int_arr,*pend=int_arr+arr_sz;pbegin<pend;++pbegin)

 					cout << *pbegin << " " << endl;

 					}																
//
