#include <iostream>
#include <set>
using namespace std;

#define MaxWeight 52
/****************************************************************
* @brief : 		0-1背包问题（回溯）
* @author : 	dyx
* @date : 		2019/7/23 14:46
* @version : 	ver 1.0
* @inparam : 
* @outparam :	输出选择的哪个物品
*****************************************************************/
int count = 0;
set<int> a;
void fill_1(int i, int curWeight, int *bag, int N, int &maxWeightInBag)
{
	//cout << ++count << endl;		// 用于记录此程序回溯调用的次数
	if (curWeight == MaxWeight || i == N)	// 到达包的极限，或者是所有物品考察完毕
	{
		if (curWeight > maxWeightInBag)		// 判断是否比包内的值大
		{
			maxWeightInBag = curWeight;
		}
		return;
	}
	fill_1( i + 1, curWeight, bag, N, maxWeightInBag);	// 不选择当前i物品，curWeight不更新
	if (curWeight + bag[i] <= MaxWeight)	// 选择当前i物品后，curWeight更新
	{
		//cout << bag[i] << endl;
		//a.insert(bag[i]);
		fill_1(i + 1, curWeight + bag[i], bag, N, maxWeightInBag);
	}
}


/****************************************************************
* @brief : 		0-1背包问题，添加每个物品的价值
* @author : 	dyx
* @date : 		2019/7/23 15:04
* @version : 	ver 1.0
* @inparam : 
* @outparam :	
*****************************************************************/
void fill_2(int i, int curWeight, int curValue, int *bag, int *val, int N, int &weightInBag, int &maxVal)
{
	if (curWeight == MaxWeight || i == N)	// 达到重量极限，或者添加完所有物品
	{
		if (curValue > maxVal)
		{
			maxVal = curValue;
			weightInBag = curWeight;
		}
		return;
	}
	fill_2(i + 1, curWeight, curValue, bag, val, N, weightInBag, maxVal);
	if (curWeight + bag[i] <= MaxWeight)
	{
		fill_2(i + 1, curWeight + bag[i], curValue + val[i],bag,val, N, weightInBag, maxVal);
	}
}


/****************************************************************
* @brief : 		0-1背包问题（回溯优化）
* @author : 	dyx
* @date : 		2019/7/23 15:48
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool memary[7][76];
int times = 0;
void fill_3(int i, int curWeight, int *bag, int N, int &weightInBag)
{
	//cout << ++times << endl;		// 用于调用此程序回溯调用的次数
	if (curWeight == MaxWeight || i == N)
	{
		if (curWeight > weightInBag)
		{
			weightInBag = curWeight;
		}
		return;
	}
	//------添加存储之后，减少了调用次数---
	if (memary[i][curWeight])
	{
		return;
	}
	memary[i][curWeight] = true;
	//---^^^^--------------
	fill_3(i + 1, curWeight, bag, N, weightInBag);
	if (curWeight+bag[i] <= MaxWeight)
	{
		fill_3(i + 1, curWeight + bag[i], bag, N, weightInBag);
	}
}



/****************************************************************
* @brief : 		0-1背包（dp）
* @author : 	dyx
* @date : 		2019/7/23 16:36
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool states[7][MaxWeight + 1];		// 默认false
int fill_dp(int *bag, int N)
{
	states[0][0] = true;	// 第一个背包不放
	if (bag[0] <= MaxWeight)
	{
		states[0][bag[0]] = true;		// 第一个物品放
	}
	for (int i = 1; i < N; ++i)		// 动态规划状态转移
	{
		for (int j = 0; j <= MaxWeight; ++j)	// 不把第i个物品放入背包
		{
			if (states[i - 1][j] == true)
			{
				states[i][j] = states[i - 1][j];	// 把上一行的状态复制下来（i不放物品）
			}
		}
		for (int j = 0; j + bag[i] <= MaxWeight; ++j)
		{
			if (states[i - 1][j] == true)
			{
				states[i][j + bag[i]] = true;		// 把第i个物品放入背包
			}
		}
	}
	for (int i = MaxWeight; i >= 0; --i)	// 把最后一行，从后往前找最重的背包的物品的组合
	{
		if (states[N - 1][i] == true)
		{
			return i;
		}
	}
	return 0;
}

/****************************************************************
* @brief : 		0-1背包问题，优化空间，使用一维数组
* @author : 	dyx
* @date : 		2019/7/23 18:47
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
bool states_2[MaxWeight + 1];
int fill_dp_2(int *bag, int N)
{
	states_2[0] = true;		// 第一个物品不放进背包
	if (bag[0] <= MaxWeight)
	{
		states_2[bag[0]] = true;	// 第一个放进背包
	}
	for (int i = 1; i < N; ++i)		// 动态规划状态转移
	{
		for (int j = MaxWeight-bag[i]; j >= 0; --j)
		{
			if (states_2[j] == true)
			{
				states_2[j + bag[i]] = true;
			}
		}
	}
	for (int i = MaxWeight; i >= 0; --i)		// 输出结果
	{
		if (states_2[i] == true)
		{
			return i;
		}
	}
	return 0;
}

/****************************************************************
* @brief : 		0-1背包问题，求最大价值，动态规划
* @author : 	dyx
* @date : 		2019/7/23 19:22
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
int fill_dp_val(int *bag, int *val, int N)
{
	int *state = new int [MaxWeight + 1];
	for (int i = 0; i < MaxWeight + 1; ++i)		// 初始化state;
	{
		state[i] = -1;
	}
	state[0] = 0;		// 第一个不放，价值0存入state
	if (bag[0] <= MaxWeight)
	{
		state[bag[0]] = val[0];		// 第一个放入背包
	}
	for (int i = 1; i < N; ++i)		// 动态规划，状态转移
	{
		for (int j = MaxWeight - bag[i]; j >= 0; --j)
		{
			if (state[j] >= 0)
			{
				int v = state[j] + val[i];
				if (v > state[j + bag[i]])
				{
					state[j + bag[i]] = v;	// 只存价值最大的
				}
			}
		}
	}
	// 找出最大值
	int maxval = -1;		// 保存最大值
	for (int i = 0; i <= MaxWeight; ++i)
	{
		if (state[i] > maxval)
		{
			maxval = state[i];
		}
	}
	delete []state;
	return maxval;
}

int main()
{
	const int N = 7;
	int bag[N] = {21, 13, 22, 11, 15, 12, 16};
	int val[N] = {16, 21, 52, 36, 45, 42, 31};
	// 回溯，0-1重量最大
	int maxWeightInBag = 0;
	fill_1(0, 0, bag, N, maxWeightInBag);
	cout << "最大可装进背包的重量是： " << maxWeightInBag << endl;
	//for (set<int>::iterator it = a.begin(); it != a.end(); ++it)
	//{
	//	cout << *it << endl;	// 本来想用set存储添加的值，但是结果不对
	//}
	fill_3(0, 0, bag, N, maxWeightInBag);
	cout << "最大可装进背包的重量是： " << maxWeightInBag << endl;
	// 回溯，0-1价值最大
	int weightInBag = 0;
	int maxVal = 0;
	fill_2(0, 0, 0, bag, val, N, weightInBag, maxVal);
	cout << "最大可装进背包的重量是：" << weightInBag << endl;
	cout << "最大可装进背包的价值是：" << maxVal << endl;
	// 动态，0-1重量最大
	cout << "最大可装进背包的重量是： " << fill_dp(bag, N) << endl;
	cout << "最大可装进背包的重量是： " << fill_dp_2(bag, N) << endl;
	cout << "最大可装进背包的价值是： " << fill_dp_val(bag, val, N) <<endl;
//	system("pause");
	return 0;
}
