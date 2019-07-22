/*
* Copyright: (c) 2019
*
* 文件名称:  BruteForce.cpp	
* 文件标识：
* 摘	要： 简称BF匹配算法，也叫作暴力匹配算法，还有的称之为朴素匹配算法
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/6/24  21:48
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#define SIZE 256
using namespace std;

bool BF(const string MainString, const string PatternString)
{
	int MainStringlen = MainString.size();
	int PatternStringlen = PatternString.size();
	int retPos = 0;
	int i = 0, j = 0;
	bool nFlag = false;
	for(i = 0; i <= MainStringlen - PatternStringlen; ++i)
	{
		retPos = i;
		for(j = 0; j < PatternStringlen; ++j)
		{
			if(PatternString[j] != MainString[i+j])
				break;
		}
		if(j == PatternStringlen)
		{
			nFlag = true;
			break;
		}
	}
	return nFlag;
}


void InitQueryArray(int* arr, int nLen)
{
	for(int i = 0; i < nLen; ++i)
	{
		arr[i] = 1;
	}
	for(int i = 1; i < nLen; ++i)
	{
		for(int j = i; j > 0; --j)
		{
			arr[i] *= 26;
		}
	}
}

bool RF(const string MainString, const string PatternString)
{
	int nlen = PatternString.size();
	int *QueryArry = new int[nlen];
	InitQueryArray(QueryArry, nlen);
	int demNum = 0;
	int prev = 0;
	for(int i = nlen - 1; i >= 0; --i)
	{
		demNum += (PatternString[i] - 'a') * QueryArry[nlen - 1 -i];
		prev += (MainString[i] - 'a') * QueryArry[nlen - 1 -i];
	}
	if(demNum == prev)
		return true;
	else
	{
		int post = 0;
		for(int i = 1; i <= MainString.size() - PatternString.size(); ++i)
		{
			post = (prev - (MainString[i - 1] - 'a') * QueryArry[nlen - 1])*26
				+ (MainString[i + nlen - 1] - 'a');
			if(demNum == post)
				return true;
			else
				prev = post;
		}
		return false;
	}
}

void GenerateBC(const char* b, int m, int *bc)
{
	for(int i = 0; i < SIZE; ++i)
	{
		bc[i] = -1;
	}
	for(int i = 0; i < m; ++i)
	{
		bc[(int)b[i]] = i;//以ASCII为下标的数组，存储该字符在模式串中的位置
	}
}

//suffix数组：数组的下标k,表示后缀子串的长度，下标对应的数组值存储的是，在模式串中
//跟好后缀{u}相匹配的子串{u*}的起始下标值
//prefix数组：来记录模式串的后缀子串是否能匹配模式串的前缀子串
void GenerateGS(const char* b, int m, int* suffix, bool* prefix)
{
	for(int i = 0; i < m; ++i)
	{
		suffix[i] = -1;
		prefix[i] = false;
	}
	for(int i = 0; i < m-1; ++i)
	{
		int j = i;
		int k = 0;
		while(j >= 0 && b[j] == b[m-1-k])
		{
			j--;
			k++;
			suffix[k] = j + 1;
		}
		if(j < 0)
			prefix[k] = true;//如果公共后缀子串也是模式串的前缀子串
	}
}

int moveByGS(int j, int m, int* suffix, bool* prefix)
{
	int k = m - 1 - j;
	if(suffix[k] != -1)  //模式串中找不到和好后缀相同的子串
		return j - suffix[k] + 1;
	for(int r = j + 2; r <= m-1; ++r)
	{
		if(prefix[m-r] == true)//公共后缀子串也是模式串的前缀子串
			return r;
	}
	return m;//以上两种情况都不满足，直接向后滑动模式串的长度
}

int BM(const char* a, int n, const char* b, int m)
{
	int* bc = new int[SIZE];
	GenerateBC(b, m, bc);
	int* suffix = new int[m];
	bool* prefix = new bool[m];
	GenerateGS(b, m, suffix, prefix);
	int i = 0;
	while(i <= n-m)
	{
		int j = 0;
		for(j = m - 1; j >= 0; --j)
		{
			if(a[i+j] != b[j])
				break;
		}
		if(j < 0)
			return i;
		int offset_x = j - bc[(int)a[i+j]];//利用坏字符规则计算滑动个数
		int offset_y = 0;
		if(j < m -1) //即存在好后缀
		{
			offset_y = moveByGS(j, m, suffix, prefix);
		}
		i += max(offset_x, offset_y);
	}
	return -1;
}



int* GetNexts(const char* b, int m)
{
	int* next = new int[m];
	next[0] = -1;
	int k = -1;
	for(int i = 1;i < m; ++i)
	{
		while(k != -1 && b[k+1] != b[i])
			k = next[k];
		if(b[k+1] == b[i])
			++k;
		next[i] = k;
	}
	return next;
}

int KMP(const char* a, int n, const char* b, int m)
{
	int* next = GetNexts(b, m);
	int j = 0;
	for(int i = 0; i < n; ++i)
	{
		while(j>0 && a[i] != b[j])
			j = next[j -1] +1;
		if(a[i] == b[j])
			++j;
		if(j == m)
			return i - m +1;
	}
	return -1;
}

int main()
{
	string mainstr = "abcdabcdddab";
	string patternstr = "cddd";
	//cout << patternstr[0] - 'a' << endl;
	if(RF(mainstr, patternstr))
		cout << "I find Pattern String" << endl;
	else
		cout << "Not Find!" << endl;
	return 0;
}