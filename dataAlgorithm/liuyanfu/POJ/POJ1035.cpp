/*
* Copyright: (c) 2019
*
* 文件名称:  POJ1035.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/18  16:35
*/


/*
题目大意：首先给定一部分单词，这部分单词用来做为dictionary的内容。再给另一部分单词，需要我们去判断这部分单词的正确性，
如果这部分输入的单词，可以在dictionary中查到，则提示它的拼写正确。如果在dictionary中查不到，可以通过三种方式，改变该
单词后去dictionary中查找，找到则在该单词的后面提示变换后可以查找到的单词。如果经过变换也无法找到，则说明该单词错的很彻底。
*/

/*
（1）没有考虑到一个单词出现两次的情况，比如输入ii，无论去掉前一个i或者后一个i最后的结果都是i，这样导致i会最终输出两次
（2）第二版超时，写的太复杂
*/
#include <stdio.h>
#include <queue>
#include <string>
#include <set>
using namespace std;
int FindIndex(char p[][16], int raw, string str);

char dict[10001][16] = {0};
char word[51][16] = {0};
int nDictLen = 0;

struct cmp
{
	bool operator()(string s1, string s2)
	{
		return FindIndex(dict, nDictLen, s1) < FindIndex(dict, nDictLen, s2);
	}
};

typedef priority_queue<string, vector<string>, cmp> saveque;
typedef set<string, cmp> saveset;
/**
* @brief
*
* @method:    FindIndex
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @Return:    int
* @author:    RF_LYF
* @since:   2019/4/19  0:07 
*/
int FindIndex(char p[][16], int raw, string str)
{
	for(int i = 0; i < raw; ++i)
	{
		if(strcmp(p[i], str.c_str()) == 0)
			return i;
	}
}
/**
* @brief
*
* @method:    IsCorrect
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/4/18  17:18 
*/
bool IsCorrect(char p[][16], int raw, char *pstr)
{
	int nstrLen = strlen(pstr);
	for(int i = 0; i < raw; ++ i)
	{
		if(strlen(p[i]) != nstrLen)
			continue;
		else
		{
			if(strcmp(p[i], pstr) == 0)
				return true;
		}
	}
	return false;
}


/**
* @brief
*
* @method:    DeleteOne
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @param:     saveque
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  17:46 
*/
void DeleteOne(char p[][16], int raw, char *pstr, saveset &s)
{
	int nstrLen = strlen(pstr);
	char stemp[16] = {0};
	for(int i = 0; i < nstrLen; ++i)
	{
		memcpy(stemp, pstr, i);
		memcpy(stemp + i, &pstr[i + 1], nstrLen - 1 - i);
		if(IsCorrect(p, raw, stemp))
			s.insert(stemp);
	}
}


/**
* @brief
*
* @method:    InsertOne
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @param:     saveque
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  17:47 
*/
void InsertOne(char p[][16], int raw, char *pstr, saveset &s)
{
	char ch = 'a';
	int nstrLen = strlen(pstr);
	char stemp[16] = {0};
	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j <= nstrLen; ++j)
		{
			memcpy(stemp, pstr, j);
			memcpy(stemp + j, &ch, 1);
			memcpy(stemp + j + 1, &pstr[j], nstrLen - j);
			if(IsCorrect(p, raw, stemp))
				s.insert(stemp);
		}
		ch++;
	}
}


/**
* @brief
*
* @method:    ReplaceOne
* @access:    public 
* @param:     char p[][16]
* @param:     int raw
* @param:     char * pstr
* @param:     saveque
* @Return:    void
* @author:    RF_LYF
* @since:   2019/4/18  21:38 
*/
void ReplaceOne(char p[][16], int raw, char *pstr, saveset &s)
{
	char ch = 'a';
	int nstrLen = strlen(pstr);
	char stemp[16] = {0};
	char str[16] = {0};
	memcpy(str, pstr, nstrLen);
	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j < nstrLen; ++j)
		{
			str[j] = ch;
			memcpy(stemp, str, nstrLen);
			if(IsCorrect(p, raw, stemp))
				s.insert(stemp);
			memcpy(str, pstr, nstrLen);
		}
		ch++;
	}
}

int main()
{
	while(scanf("%s",dict[nDictLen]) && strcmp(dict[nDictLen], "#"))
		nDictLen++;
	int nWordLen = 0;
	while(scanf("%s", word[nWordLen]) && strcmp(word[nWordLen], "#"))
		nWordLen++;
	for(int i = 0; i < nWordLen; ++i)
	{
		if(IsCorrect(dict, nDictLen, word[i]))
			printf("%s is correct\n", word[i]);
		else
		{
			saveset s;
			DeleteOne(dict, nDictLen, word[i], s);
			InsertOne(dict, nDictLen, word[i], s);
			ReplaceOne(dict, nDictLen, word[i], s);
			printf("%s:", word[i]);
			set<string, cmp>::iterator it = s.begin();
			while(it != s.end())
			{
				printf(" %s", (*it).c_str());
				++it;
			}
			printf("\n");
		}
	}
	return 0;
}