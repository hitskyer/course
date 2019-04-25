/**
 * poj 1064,
 * 摘要：有N条电缆，各种长度，现在需要require条，且长度相等，最大。
 * 方法：二分求解，类似分pie的问题
 *
 */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double arr[10001];
int main()
{
	int N = 0;
	cin >> N;
	int require;
	cin >> require;
	int sum = 0;
	double low = 0.00;
	double high = 100000;
	double mid = 0.00;
	double x = 0.00;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		//high = high > arr[i] ? high : arr[i];
	}
	
	while((high - low) > 1e-3)
	{
		sum = 0;
		mid = low + (high - low)/2;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] >= mid)
				sum += int(arr[i]/mid);
		}
		if (sum >= require)
			low = mid;
		else
			high = mid;
	}
	cout << fixed << setprecision(2) << floor(high*100)/100 << endl;
//	system("pause");
	return 0;
}
