#include "matchString.h"
#include <iostream>
#include<stdio.h>
//using namespace std;
match::match()
{
}

match::~match()
{
}

int match::bfMatch(string s, string t)
{
	int i = 0;
	int j = 0;
	while(i < s.length() && j < t.length())
	{
		if(s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j >= t.length())
		return i - t.length();
	else
		return -1;
}

void match::getNext(string p, int next[])
{
	int pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while( j < pLen - 1)
	{
		if(k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			if(p[j] != p[k])
				next[j] = k;
			else
				next[j] = next[k];
		}
		else
			k = next[k];
	}
}

int match::kmpMatch(string s, string p)
{
	int i = 0;
	int j = 0;
	int sLen = s.length();
	int pLen = p.length();
	int next[255];
	getNext(p, next);
	while(i < sLen && j < pLen)
	{
		if(j == -1 || s[i] == p[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j == pLen)
		return i - j;
	else
		return -1;
}
