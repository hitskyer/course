#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<string> svec1;
	vector<string> svec2;
	vector<string> svec3;
	vector<string> svec4;
	svec1.reserve(1024);
	svec2.reserve(1024);
	svec3.reserve(1024);
	svec4.reserve(1024);
// 输入256个单词
	for(vector<string>::size_type ix=0; ix!=256; ++ix)
		svec1.push_back("Hello");
	svec1.resize(svec1.size()+svec1.size()/2);
	cout << "svec1_capacity(push 256 words): " << svec1.capacity() << endl;
//输入512 个单词
	for(vector<string>::size_type ix=0; ix!=512;++ix)
		svec2.push_back("Hello");
	svec2.resize(svec2.size()+svec2.size()/2);
	cout << "svec2_capactiy(push 512 words): " << svec2.capacity() << endl;
//输入1000单词
	for(vector<string>::size_type ix=0;ix!=1000;++ix)
		svec3.push_back("Hello");
	svec3.resize(svec3.size()+svec3.size()/2);
	cout << "svec3.capacity(push 1000 words): " << svec3.capacity() << endl;
//输入1048 单词
	for(vector<string>::size_type ix=0;ix!=1048;++ix)
		svec4.push_back("Hello");
	svec4.resize(svec4.size()+svec4.size()/2);
	cout << "svec4.capacity(push 1048 words): " << svec4.capacity() << endl;
	return 0;
}

