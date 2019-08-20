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
			if(arrmin[j] > arrmax[j + 1])
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

void Coverage(int *arrmin, int *arrmax, int len, char *c)
{
	sortSmallBig(arrmin, arrmax, len);
	c[0] = '1';
	int index = 0;
	for(int i = 1; i < len; ++i)
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

int main()
{
	int Imin[6] = {0,2,3,1,5,8};
	int Imax[6] = {3,4,5,5,9,10};
	char c[6] = {'0','0','0','0','0','0'};
	Coverage(Imin, Imax, 6, c);
	print(Imin, Imax, c, 6);
	return 0;
}
