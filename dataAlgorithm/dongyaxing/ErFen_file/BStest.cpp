#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "BinarySearch.h"
using namespace std;


int main()
{
	std::cout << "求解下列平方根：" << endl << endl;
	double val1 = 15.0;
	double val2 = 0.6;
	double val3 = 49.0;
	double val4 = 0.7;
	std::cout << "二分求解："<< endl;
	std::cout << val1 << "的平方根是 : "  <<FindRoot(val1) << endl;
	std::cout << val2 << "的平方根是 : " <<FindRoot(val2) << endl;
	std::cout << val3 << "的平方根是 : " <<FindRoot(val3) << endl;
	std::cout << val4 << "的平方根是 : " <<FindRoot(val4) << endl << endl << endl;
	std::cout << "公式求解:"<< endl;
	std::cout << val1 << "的平方根是 : " <<fixed << setprecision (7) <<Squre(val1) << endl;
	std::cout << val2 << "的平方根是 : " <<fixed << setprecision (7) <<Squre(val2) << endl;
	std::cout << val3 << "的平方根是 : " <<fixed << setprecision (7) <<Squre(val3) << endl;
	std::cout << val4 << "的平方根是 : " <<fixed << setprecision (7) <<Squre(val4) << endl << endl;


	int arr[20] = {1,2,3,4,5,6,7,8,8,8,9,9,10,10,11,12,14,14,15,16};
	std::cout << "在数组中，查找某个数，并返回下标：" << endl;
	std::cout << "测试数组：" <<endl;
	for (int i = 0; i < 20; ++i)
	{
		std::cout << arr[i] << "  ";
	}
	cout << endl << endl;

	cout << "查找一个8，返回索引："<< BioSearch(arr, 20, 8) << endl;
	cout << "查找一个13，返回索引："<< BioSearch(arr, 20, 13) << endl << endl;

	cout << "查找第一个8（顺序查找），返回索引：" << BioSearch_1(arr, 20, 8) << endl;
	cout << "查找第一个8（二分查找），返回索引：" << BioSearch_2(arr, 20, 8) << endl;
	cout << "查找最后一个值8，返回索引：" << BioSearch_3(arr, 20, 8) << endl << endl;

	cout << "查找第一个大于等于给定值的元素，返回索引：" << BioSearch_4(arr, 20, 13) << endl;
	cout << "查找最后一个小于等于给定值的元素，返回索引：" << BioSearch_5(arr, 20, 13) << endl;

//	system("pause");
	return 0;
}
