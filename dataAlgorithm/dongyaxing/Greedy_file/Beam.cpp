#include<iostream>
#include<string>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(char &c1, char &c2)
{
	char temp;
	temp = c1;
	c1 = c2;
	c2 = temp;
}

void compute(int *wei, int *total, int *single, int len)
{
	for(int i = 0; i < len; ++i)
	{
		single[i] = total[i]/wei[i];
	}
}

void sortSmallBig(int *wei, int *total, int *single, char *b, int len)
{
	bool flag = true;
	for(int i = 0; i < len - 1; ++i)
	{
		flag = true;
		for(int j = 0; j < len - i - 1; ++j)
		{
			if(single[j] > single[j + 1])
			{
				swap(single[j], single[j + 1]);
				swap(wei[j], wei[j + 1]);
				swap(total[j], total[j + 1]);
				swap(b[j], b[j + 1]);
				flag = false;
			}
		}
		if(flag)
			break;
	}
}

void print(int *arr, int len)
{
	for(int i = 0; i < len; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void print(char *c, int len)
{
	for(int i = 0; i < len; ++i)
        {
                cout << c[i] << ", ";
        }
        cout << endl;
}

void putInBag(int *wei, int *single, int len, char *b, int need)
{
	while(need > 0)
	{
		for(int i = len - 1; i >= 0; --i)
		{
			if(need >= wei[i])
			{
				need -= wei[i];
				cout << "need " << b[i] << " bean" << wei[i] << " kg" << endl;
			}
			else if(need > 0)
			{
				cout << "need " << b[i] << " bean" << need << " kg" << endl;
				need = 0;
			}
			else
				break;
		}
	}
}

int main()
{
	int weight[5] = {100, 30, 60, 20, 50};
	int totalVal[5] = {100, 90, 120, 80, 75};
	int singleVal[5] = {0,0,0,0,0};
	char bean[5] = {'y', 'g', 'r', 'b', 'q'};
	compute(weight, totalVal, singleVal, 5);		// 计算单价
	sortSmallBig(weight, totalVal, singleVal, bean, 5);	// 排序
	cout << "输出排序后的重量： " << endl;
	print(weight, 5);
	cout << "输出排序后的总价： " << endl;
	print(totalVal, 5);
	cout << "输出排序后的单价： " << endl;
	print(singleVal, 5);
	cout << "输出豆子种类：b-黑豆，g-绿豆，q-青豆，r-红豆，y-黄豆"<< endl;
	print(bean, 5);
	cout << "输出需要的哪种豆子，多少千克。" << endl;
	putInBag(weight, singleVal, 5, bean, 100);
	return 0;
}
