#include <iostream>
#include <stdlib.h>

using namespace std;


/****************************************************************
* @brief : 		pay RMB
* @author : 	dyx
* @date : 		2019/7/6 15:41
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
class payMoney
{
public:
	payMoney();
	~payMoney();
	int howManyCash(int waitToPay);
private:
	int *arr;
};

payMoney::payMoney()
{
	arr= new int[6];
	arr[0] = 100;
	arr[1] = 50;
	arr[2] = 20;
	arr[3] = 10;
	arr[4] = 5;
	arr[5] = 1;
}
payMoney::~payMoney()
{
	delete [] arr;
}

/****************************************************************
* @brief : 		payRMB
* @author : 	dyx
* @date : 		2019/7/6 15:42
* @version : 	ver 1.0
* @inparam :	need to pay RMB
* @outparam : 
*****************************************************************/
int payMoney::howManyCash(int waitToPay)
{
	int count = 0;
	int num;
	for (int i = 0; i < 6; ++i)
	{
		num = waitToPay/arr[i];
		if (num >= 1)
		{
			count += num;
			cout << "need " << num << " " << arr[i] << "RMB" << endl;
			waitToPay -= num * arr[i];
		}
	}
	cout << "total need " << count <<" RMB." << endl;
	return count;
}

/****************************************************************
* @brief : 		distribute candy
* @author : 	dyx
* @date : 		2019/7/6 15:43
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
class candyDistribute
{
public:
	candyDistribute();
	~candyDistribute();
	void distribute(int *kid, int kidnum, int *candy, int candynum);
	void print(int *arr, int len);
private:
	void sortSmallBig(int *arr, int len);
};

candyDistribute::candyDistribute()
{
}

candyDistribute::~candyDistribute()
{
}

/****************************************************************
* @brief : 		candy and kid sort small to big
* @author : 	dyx
* @date : 		2019/7/6 15:43
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void candyDistribute::sortSmallBig(int *arr, int len)
{
	int preIndex, current;
	for (int i = 1; i < len; ++i)
	{
		preIndex = i - 1;
		current = arr[i];
		while(preIndex >= 0 && arr[preIndex] > current)
		{
			arr[preIndex +1] = arr[preIndex];
			--preIndex;
		}
		arr[preIndex + 1] = current;
	}
}

void candyDistribute::print(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void candyDistribute::distribute(int *kid, int kidnum, int *candy, int candynum)
{
	sortSmallBig(kid, kidnum);
	sortSmallBig(candy, candynum);
	int kidcurrent = 0;
	int candycurrent = 0;
	while (kidcurrent < kidnum && candycurrent < candynum)
	{
		if (kid[kidcurrent] <= candy[candycurrent])
		{
			cout << " kid " << kid[kidcurrent] << " match " << " candy " << candy[candycurrent] << endl;
			++kidcurrent;
			++candycurrent;
		}
		else
		{
			++candycurrent;
		}
	}
	if (kidcurrent == kidnum)
	{
		cout << "perfect! every kid own a candy." << endl;
	}
	else
	{
		cout << "just satisfy " << kidcurrent << " kids!" << endl; 
	}
}

int main()
{
	// payRMN:
	payMoney pmoney;
	cout << "please input need to pay monay: " << endl;
	int money;
	cin >> money;
	if (money > 65534)
	{
		cout << "Illegal input!!!"<<endl;
	}
	else
	{
		pmoney.howManyCash(money);
	}
	
	// distribute candy:
	candyDistribute candyD;
	int kid[] = {5,10,2,9,15,9,10};
	int candy[] = {6,1,20,3,8,12,18};
	cout << "kid need: "<< endl;
	candyD.print(kid, 7);
	cout << "canny weight:" <<endl;
	candyD.print(candy,7);
	cout << "kid match candy;" << endl;
	candyD.distribute(kid,7,candy,6);
	cout << "kid need sort : "<< endl;
	candyD.print(kid, 7);
	cout << "canny weight sort :" <<endl;
	candyD.print(candy,7);

//	system("pause");
	return 0;
}
