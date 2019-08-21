#include<iostream>
using namespace std;

static int num = 0;		// 全局变量，记录逆序对数
void merge(int *a, int p, int q, int r);
void mergeSortCounting(int *a, int p, int r);

int count(int *a, int n)
{
	num = 0;
	mergeSortCounting(a, 0, n - 1);		// 通过归并，计算继续对数
	return num;
}
// inparam: 数组，起始，终止
void mergeSortCounting(int *a, int p, int r)
{
	if(p >= r)
		return;
	int q = (p + r) / 2;
	mergeSortCounting(a, p, q);
	mergeSortCounting(a, q + 1, r);
	merge(a, p, q, r);
}
// 合并
void merge(int *a, int p, int q, int r)
{
	int i = p, j = q + 1, k = 0;
	int *temp = new int[r-p+1];	// a的所有的数
	while(i <= q && j <= r)		// i j小于自己的终止范围
	{
		if(a[i] <= a[j])	// 正序
			temp[k++] = a[i++];
		else
		{
			num += (q - i + 1);	// 逆序
			temp[k++] = a[j++];
		}
	}
	while(i <= q)		// 前半段剩余，直接赋值
	{
		temp[k++] = a[i++];
	}
	while(j <= r)		// 后半段剩余，直接赋值
	{
		temp[k++] = a[j++];
	}
	for(i = 0; i <= r-p; ++i)	// 对于temp里面排序好的数，直接复制回到a数组中
	{
		a[p + i] = temp[i];
	}
}

void print(int *a, int len)
{
	for(int i = 0; i < len; ++i)
        {
                cout << a[i] << ", ";
        }
	cout << endl;
}

int loop(int *a, int len)
{
	//bool flag = true;
	int n = 0;
	//int temp = 0;
	for(int i = 0 ; i < len - 1; ++i)
	{
		//flag = true;
		for(int j = i; j < len - 1; ++j)
		{
			if(a[i] > a[j + 1])
			{
				++n;
				//temp = a[j];
				//a[j] = a[j + 1];
				//a[j + 1] = temp; 
				//flag = false;
			}
		}	
		//if(flag)
		//	break;
	}
	return n;
}

int main()
{
	int arr[9] = {4,6,2,7,1,8,5,9,3};
	cout << "数据如下，求其逆序对数：" << endl;
	print(arr, 9);
	cout << "采用分治思想，调用归并算法，求的逆序对数为： " << endl;
	count(arr, 9);
	cout << num << endl;
	cout << "排序之后：" << endl;
	print(arr, 9);
	cout << endl;
	int brr[9] = {4,6,2,7,1,8,5,9,3};
	cout << "采用循环，求的逆序对数为： " << endl;
	cout << loop(brr, 9) << endl;
//	cout << "排序之后： " << endl;
//	print(brr, 9);
	return 0;
}
