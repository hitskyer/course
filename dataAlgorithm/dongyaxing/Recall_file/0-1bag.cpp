#include<iostream>
#define MAX_WEIGHT 100
using namespace std;


// arr 待装包的物品重量，
// curweight 当前i物品的重量
// i 当前即将放入的i物品
// num 可用物品的数量
// bagweight 当前背包的总重量
void fill(int *arr, int curweight, int i, int num, int &bagweight)
{
	if(curweight == MAX_WEIGHT || i == num)	// 装满，或者考察完所有物品
	{
		if(curweight > bagweight)
		{
			bagweight = curweight;		// 记录历史最大装载量
		//	cout << bagweight << "***" << endl << endl;
		}
		return;
	}
	fill(arr, curweight, i + 1, num, bagweight);	// 不选择i物品
	if(curweight + arr[i] <= MAX_WEIGHT)	// 选择当前i物品， curweight更新
	{
		fill(arr, curweight + arr[i], i + 1, num, bagweight);
		//cout << bagweight << "---" << endl;
	}
}


int main()
{
	int a[10] = {50, 45, 43, 33, 30, 29, 27, 26, 25, 15};
        int b[10] = {54, 45, 43, 39, 36, 31, 28, 22, 16, 14};

	int bagweight = 0;
	fill(a, 0, 0, 10, bagweight);
	cout << "a包内的物品： " << bagweight<< endl;

	bagweight = 0;
	fill(b, 0, 0, 10, bagweight);
	cout << "b包内的物品： " << bagweight << endl;
	return 0;
}

// 尝试打印输出装包过程，但是没看明白
