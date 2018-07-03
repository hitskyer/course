#include<iostream>
using namespace std;
int main()
{
	int *p = new int [10];
	//int **t = p;
	int *a = p;
	p++;
	cout << p << endl << *p << endl; //<< **p ;
	//cout << t << endl << *t << endl;
	delete [] a;
	p = NULL;
	
}
