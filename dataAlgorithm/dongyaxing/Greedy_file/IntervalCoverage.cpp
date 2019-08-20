#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

// 把区间数据，按照开始位置，由小到大排序
// 两个数组长度相同
void sortSmallBig(int *arrmin, int *arrmax, int len)
{
	bool flag = true;
	for(int i = 0; i < len - 1; ++i)
	{
		flag = true;
		for(int j = 0; j < len - i - 1; ++j)
		{
			if(arrmin[j] > arrmin[j + 1])
			{
				swap(arrmin[j], arrmin[j + 1]);
				swap(arrmax[j], arrmax[j + 1]);
				flag = false;
			}
		}
		if(flag)
			break;
	}
}

void Coverage(int *arrmin, int *arrmax, int len, char *c, int k)
{
	c[k] = '1';
	int index = k;
	for(int i = k; i < len; ++i)
	{
		if(arrmin[i] >= arrmax[index])
		{
			c[i] = '1';
			index = i;
		}
	}
}

void print(int *arrmin, int *arrmax, char *c, int len)
{
	for(int i = 0; i < len; ++i)
	{
		if(c[i]=='1')
		{
			cout << "start: " << arrmin[i] << "  end: " << arrmax[i] << endl;
		}
	}
}

void printArr(int *arr, int len)
{
	for(int i = 0; i < len; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main()
{
	int Imin[6] = {0,2,3,1,5,8};
	int Imax[6] = {3,4,5,5,9,10};
	char c[6] = {'0','0','0','0','0','0'};
	sortSmallBig(Imin, Imax, 6);
	printArr(Imin, 6);
	printArr(Imax, 6);
	
	sortSmallBig(Imin, Imax, 6);
	for(int k = 0; k < 5; ++k)
	{
		Coverage(Imin, Imax, 6, c, k);
		print(Imin, Imax, c, 6);
		cout << " *****8<*****" << endl;
		for(int i = 0; i < 6; ++i)
		{
			c[i] = '0';
		}
	}
	
	return 0;
}
