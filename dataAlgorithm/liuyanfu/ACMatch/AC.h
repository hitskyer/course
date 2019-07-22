/*
* Copyright: (c) 2019
*
* 文件名称:  AC.h	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/7/8  10:08
*/

#ifndef _AC_H
#define _AC_H

#include <string.h>
#include <vector>

struct PosSet
{
	std::vector<int> vPos;
	std::vector<int> vLen;
};



class ACNode
{
public:
	ACNode(const char ch):isEndingChar(false), length(-1), nodeNum(0), pFail(NULL)
	{
		data = ch;
		memset(child, 0, sizeof(child));
	}

	ACNode():isEndingChar(false), length(-1), nodeNum(0), pFail(NULL)
	{
		memset(child, 0, sizeof(child));
	}

	bool operator ==(const ACNode& b)
	{
		return data == b.data;
	}

	~ACNode(){}

	char data;
	ACNode* child[26];
	bool isEndingChar;
	int length;
	int nodeNum;
	ACNode* pFail;
};


class AC
{
public:
	AC(void);
	~AC(void);
	template<typename Iterator>
	void insert(Iterator begin, Iterator end);
	template<typename Iterator>
	bool find(Iterator begin, Iterator end);
	template<typename Iterator>
	void match(Iterator begin, Iterator end, PosSet* ret);
	void insert(const char* text);	
	bool find(const char* pattern);
	void buildFailurePointer();	
	void match(const char* text, PosSet* ret);
	void print(const char* text);
	void clear();
private:
	ACNode* root;
	void clear_node(ACNode cur);
};

#endif //_AC_H