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

	// ***1*** Ã°ÅÝÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.Bobble();
	finish = clock();
	cout << "Bobble sort spend time : " << (finish - start)<< " ms" <<endl;*/
	//sc.PrintSort();

	// ***2*** Ñ¡ÔñÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.Select();
	finish = clock();
	cout << "Select sort spend time : " << (finish - start)<< " ms" <<endl;*/
	//sc.PrintSort();  

	// ***3*** ²åÈëÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.InsertArr();
	finish = clock();
	cout << "InsertArr sort spend time : " << (finish - start)<< " ms" <<endl;*/
	//sc.PrintSort();  

	// ***4*** Ï£¶ûÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.Shell();
	finish = clock();
	cout << "Shell sort spend time : " << (finish - start)<< " ms" <<endl;*/
	//sc.PrintSort();
	
	// ***5*** ºÏ²¢ÅÅÐò
	/*int result_1[NUM_SIZE];
	sc.InitTempArr();
	start = clock();
	sc.MergeSort(sc.temparr, 0, NUM_SIZE - 1, result_1);
	finish = clock();
	cout << "MergeSort sort spend time : " << (finish - start)<< " ms" <<endl;*/
	//sc.PrintSort();

	//int data[] = {9,6,7,12,20,6,33,16,20,18,26};		// ×î³õµÄ11¸öÔªËØ
	//const int length = 11;
	//int result[length];		// ÐÂ¿ª±Ù¿Õ¼ä
	//sc.MergeSort(data, 0, length -1, result);
	//for (int i = 0; i < 11; ++i)
	//{
	//	cout << data[i] << "  ";
	//}
	//cout << endl;

	// ***6*** ¿ìËÙÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.QuickSort(sc.temparr, 0, 499);
	finish = clock();
	cout << "spend time: " << finish - start << "ms" << endl;
	sc.PrintSort();*/

	// ***7*** Í°ÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.BucketSort(sc.temparr, BUCKET_NUM);
	finish = clock();
	cout << "Bucket Sort spend time : " << finish - start << "ms" << endl;
	sc.PrintSort();*/

	//***8*** ¼ÆÊýÅÅÐò
	/*sc.InitTempArr();
	start = clock();
	sc.CountSort(sc.temparr);
	finish = clock();
	cout << "Count Sort spend time : " << finish - start << "ms" << endl;
	sc.PrintSort();*/

	//***9*** »ùÊýÅÅÐò
	sc.InitTempArr();
	start = clock();
	sc.RadixSort(sc.temparr, NUM_SIZE);
	finish = clock();
	cout << "Radix Sort spend time : " << finish - start << "ms" << endl;
	sc.PrintSort();
	
//	system("pause");
	return 0;
}
