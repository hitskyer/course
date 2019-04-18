#include <iostream>
using namespace std;
// 递归，深度到40，就需要7s才完成
unsigned int step_1(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
		return step_1(n-1) + step_1(n-2);
}
// 通过arr记录台阶数，即使n=118，也能瞬间出结果。
unsigned int step_2(int n, unsigned int *arr)
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	if (arr[n] > 0)
	{
		return arr[n];
	}
	if (n == 1 || n == 0)
	{
		return arr[1];
	}
	else if (n == 2)
	{
		return arr[2];
	}
	else
	{
		arr[n] = step_2(n-1, arr) + step_2(n-2, arr);
	}
	return	arr[n];
}
// 用循环实现
unsigned int step_3(int n)
{
	unsigned int sum;
	unsigned int a = 1, b = 2;
	if (n == 0 || n ==1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
	{
		for (int i = 3; i <= n; ++i)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
		return sum;
	}
}
// 左右(奇偶)脚问题
/*
假设奇数步为左脚，偶数步到为右脚，每次先迈左脚。
n = 1   f奇(1) = 1		f偶(1) = 0
n = 2	f奇(2) = 1		f偶(2) = 1
n = 3	f奇(3) = 1		f偶(3) = 2
n = 4	f奇(4) = 3		f偶(4) = 2
规律：
	f奇(n) = f偶(n - 1) + f偶(n - 2)
	f偶(n) = f奇(n - 1) + f奇(n - 2)
*/
// 求最后是右脚到达
unsigned int step_4(size_t n)
{
	int left_1 = 1, left_2 = 1;
	int right_1 = 0, right_2 = 1;
	int left = 0;
	int right = 0;
	if (n == 1)
	{
		return right_1;
	}
	else if (n == 2)
	{
		return right_2;
	}
	else
	{
		for (size_t i = 3; i <= n; ++i)
		{
			right = left_1 + left_2;

			left = right_1 + right_2;

			left_1 = left_2;
			left_2 = left;

			right_1 = right_2;
			right_2 = right;
		}
		return right;
	}
}
int main()
{
	std::cout << "请输入台阶数： " ;
	int n;
	cin >> n;
	cout << "走台阶有 " << step_1(n) << " 种方案。" << endl << endl;

	unsigned int arr[110] = {0};	// 此处的数组长度，应该大于输入的 n，且必须初始化0
	cout << "走台阶有 " << step_2(n, arr) << " 种方案。" << endl << endl;

	cout << "走台阶有 " << step_3(n) << " 种方案。" << endl << endl;
	cout << "左脚开始，右脚到达。走台阶有 " << step_4(n) << " 种方案。" << endl << endl;
//	system("pause");
	return 0;
}
