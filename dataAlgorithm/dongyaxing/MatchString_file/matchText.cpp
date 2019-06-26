#include<stdio.h>
#include<iostream>
#include"matchString.cpp"
using namespace std;

int main()
{
	match mc;
	string s = "ababababaaabasa";
	string T = "ababaaaba";
	size_t index = 0;
	index = mc.bfMatch(s, T);
	cout << "index : " << index << endl;

	string str = "ababababaaabasa";
	string t = "ababaaaba";
	index = mc.kmpMatch(str, t);
	cout << "index : " << index << endl;

	return 0;
}
