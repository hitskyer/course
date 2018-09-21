#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;

int main(int argc, char** argv)
{
	//定义对象
	map<string, string> trans_map;
	string key, value;
	if(agrc!=3)
		throw runtime_error("wrong number of arguments");
	
	//打开a.txt转换文件，判断是否打开
	ifstream map_file;
	if(!open_file(map_file, argv[1]))
		throw runtime_error("no transformation file");
	
	//读入a.txt内容，并转换为map对
	while(map_file >> key >> value)
		trans_map.insert(make_pair(key, value));

	//打开b.tx文件，判断是否打开
	ifstream input;
	if(!open_file(input,argv[2]))
		runtime_error("no input file");
	
	string line;
	//按照行读取内容
	while(getline(input, line))
	{
		istringstream stream(line);
		string word;
		bool firstword = true;
		while(stream(word))
		{
			map<string, string>::const_iterator map_it = trans_map.find(word);
			if(map_it != trans_map.end())
				word = map_it->second;
			if(firstword)
				firstword = false;
			else 
				cout<<" ";
			cout<<word;
		}
		cout<<endl;
	}
	return 0;
}
