#ifndef _ACMATCH_H
#define _ACMATCH_H

#include<iostream>
#include <string.h>
#include <vector>

using namespace std;
// 用于标记在主串中的位置及长度
struct PosSet
{
	std::vector<int> vPos;
	std::vector<int> vLen;
};

// trie数结构
class ACNode
{
public:
	// 允许用字符初始化变量
	ACNode(const char ch):isEndingChar(false), length(-1), nodeNum(0), pFail(NULL)
	{
		data = ch;
		memset(child, 0, sizeof(child));
	}
	// 默认构造函数，初始化变量
	ACNode():isEndingChar(false), length(-1), nodeNum(0), pFail(NULL)
	{
		memset(child, 0, sizeof(child));
	}

	bool operator == (const ACNode &b)
	{
		return data == b.data;
	}

	~ACNode(){};

	char data;
	ACNode* child[26];		// 数组里面存储的是26个ACNode*
	bool isEndingChar;		// 是否为结尾字符
	int length;				// 当isEndingChar = true,记录模式串的长度
	int nodeNum;			// 记录结点个数
	ACNode* pFail;			// 失效结点
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
	void match(Iterator begin, Iterator end, PosSet *ret);

	void insert(const char* text);

	bool find(const char* pattern);

	void buildFailurePointer();

	void match(const char* text, PosSet* ret);

	void print(const char* text);

	void clear();
private:
	ACNode *root;		// 模式串的根结点
	void clear_node(ACNode cur);
};

#endif //_ACMATCH_H