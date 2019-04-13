#include "Sort.h"
#include "Sort.cpp"
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

int main()
{
	clock_t start, finish;
	SortClass sc;
	cout << "produce rand arr :"<<endl;
	sc.RandNum();
	cout << "print original arr[]: " <<endl;
	//sc.Print();
	cout << endl;

	sc.InitTempArr();
	start = clock();
	sc.Bobble();
	finish = clock();
	cout << "Bobble sort spend time : " << (finish - start)<< " ms" <<endl;
	//sc.PrintSort();

	sc.InitTempArr();
	start = clock();
	sc.Select();
	finish = clock();
	cout << "Select sort spend time : " << (finish - start)<< " ms" <<endl;
	//sc.PrintSort();  

	sc.InitTempArr();
	start = clock();
	sc.InsertArr();
	finish = clock();
	cout << "InsertArr sort spend time : " << (finish - start)<< " ms" <<endl;
	//sc.PrintSort();  

	//system("pause");
	return 0;
}
