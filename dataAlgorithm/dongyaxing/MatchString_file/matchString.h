#ifndef _MATCHSTRING_H
#define _MATCHSTRING_H
#include<iostream>
#include<string>
using namespace std;
class match
{
public:
	match();
	~match();

	//暴力求解，返回匹配索引，不存在则返回-1
	int bfMatch(string str, string t);
	
	// kmp求解，返回匹配索引，不存在，则返回-1
	// 求解next数组
	void getNext(string p, int next[]);
	int kmpMatch(string s, string p);
};


#endif
