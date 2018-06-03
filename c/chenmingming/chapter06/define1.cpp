#include<iostream>
#define squ(n) n*n
#define squ1(a,b) b*a

//#define debug
using namespace std;
int s(int a)
{
	return a*a;
}
main()
{
	cout << "R= "<< 27.0/squ(3.0) <<endl;
	cout << "R= "<< 27.0/s(3.0) <<endl;
	cout << "R= "<< squ1(1+2,2+3) <<endl;
	#if 3 
	cout << "AAA " <<endl;
	#else
	cout << "BBB " <<endl;
	#endif
	
	#ifdef debug
	cout << "CCC"<<endl;
	#else
	cout << "DDD"<<endl;
	#endif
	
}
